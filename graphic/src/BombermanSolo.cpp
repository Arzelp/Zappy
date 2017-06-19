//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Fri Jun 16 10:39:25 2017 arnaud.alies
//

#include <string>
#include <iostream>
#include "BombermanSolo.hpp"
#include "MainMenu.hpp"
#include "Box.hpp"
#include "Gate.hpp"
#include "Monster.hpp"
#include "Plane.hpp"
#include "SoloEndMenu.hpp"
#include "Random.hpp"

BombermanSolo::BombermanSolo() :
  _core(nullptr),
  _entity_manager(nullptr),
  _time_end(0),
  _state(G_RUNNING)
{
  _level = 1;
}

BombermanSolo::BombermanSolo(int level) :
  _core(nullptr),
  _entity_manager(nullptr),
  _time_end(0),
  _state(G_RUNNING)
{
  _level = level;
  if (_level < 1)
    _level = 1;
}


BombermanSolo::~BombermanSolo()
{
  if (SETTINGS.max_level < _level)
    SETTINGS.max_level = _level;
  delete _entity_manager;
  delete _map;
  delete _background;
  _staticText->remove();
}

void BombermanSolo::respawnPlanes()
{
  std::vector<AEntity*> ents;
  int diff;
  int x;
  int y;

  ents = _entity_manager->getAll("plane");
  diff = _level - ents.size();
  while (diff > 0)
    {
      do {
	x = Random::randint(1, _map->getWidth() - 2);
	y = Random::randint(1, _map->getHeight() - 2);
      } while (_map->get(x, y) != M_EMPTY);
      _entity_manager->addEntityMap<Plane>(x, y);
      x = 0;
      y = 0;
      diff -= 1;
    }
}

State *BombermanSolo::update()
{
  if (_state == G_RUNNING)
    {
      if (_core->receiver->keyState(K_ESCAPE))
	return (new MainMenu());
      if (_p1->isAlive() == false)
	{
	  _state = G_LOST;
	  _time_end = _core->getTimeMs();
        }
      std::vector<AEntity*> ents;
      ents = _entity_manager->getInRange(_p1->getPos(), UNIT / 2, "gate");
      if (ents.size() > 0 && _state == G_RUNNING)
	{
	  _time_end = _core->getTimeMs();
          _state = G_WON;
	}
      this->respawnPlanes();
      _entity_manager->update();
    }
  else
    {
      if (_time_end < _core->getTimeMs() - WAIT_AFTER_DEATH)
	{
	  if (_state == G_LOST)
	    {
	      return (new SoloEndMenu(0));
	    }
	  if (_state == G_WON)
	    return (new SoloEndMenu(_level));
	}
    }
  return (nullptr);
}

void BombermanSolo::spawnBoxes()
{
  std::vector<AEntity*> in_range;

  for (int y = 0; y < _map->getHeight(); y += 1)
    for (int x = 0; x < _map->getWidth(); x += 1)
      {
	if (_map->get(x, y) == M_EMPTY)
	  {
	    in_range = _entity_manager->getInRange(Map::getAbs(x, y), UNIT * 2, "player:npc");
	    if (in_range.size() <= 0
		&& RAND_PERCENT(40)
		&& x != _map->getWidth() - 2 && _map->getHeight() - 2)
	      _entity_manager->addEntityMap<Box>(x, y);
	  }
      }
}

void BombermanSolo::spawnMonsters()
{
  std::vector<AEntity*> in_range;
  int x, y;
  int n = _level;

  while (n > 0)
    {
      do {
        x = Random::randint(1, _map->getWidth() - 2);
        y = Random::randint(1, _map->getHeight() - 2);
      } while (_map->get(x, y) != M_EMPTY
	       || _entity_manager->getInRange(Map::getAbs(x, y), UNIT * 4, "player").size() > 0);
      _entity_manager->addEntityMap<Monster>(x, y);
      x = 0;
      y = 0;
      n -= 1;
    }
}

void BombermanSolo::begin(Core* core)
{
  _core = core;
  _map = new Map(_core, SETTINGS.map_size, SETTINGS.map_size);
  _entity_manager = new	EntityManager(_core, _map);

  _background = new Image(core,
                          core->video->getTexture((char*)"./res/background.png"),
                          irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT * 0.86));

  _staticText =
    _core->gui->addStaticText((irr::core::stringw("Top level: ")
			       + irr::core::stringw(SETTINGS.max_level)
			       + irr::core::stringw("\nCurrent level: ")
			       + irr::core::stringw(_level)).c_str(),
			      irr::core::rect<irr::s32>(10,10,260,70),
			      false);
  
  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;

  _core->cam->setPosition(irr::core::vector3df(width / 4, width, height / 2));
  _core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));

  _p1 = _entity_manager->addEntityMap<Player1>(1, 1);
  _entity_manager->addEntityMap<Gate>(_map->getWidth() - 2, _map->getHeight() - 2);
  //_entity_manager->addEntityMap<Monster>(_map->getWidth() - 2, _map->getHeight() - 2);
  
  _entity_manager->update();
  this->spawnMonsters();
  _entity_manager->addEntityMap<Plane>(3, 3);

  _entity_manager->update();
  this->spawnBoxes();
}
