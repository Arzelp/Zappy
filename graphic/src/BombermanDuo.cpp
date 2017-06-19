//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Fri Jun 16 10:41:47 2017 arnaud.alies
//

#include <iostream>
#include "BombermanDuo.hpp"
#include "DuoEndMenu.hpp"
#include "MainMenu.hpp"
#include "Box.hpp"
#include "Random.hpp"

BombermanDuo::BombermanDuo() :
  _core(nullptr),
  _entity_manager(nullptr),
  _time_end(0),
  _running(true)
{
}

BombermanDuo::~BombermanDuo()
{
  delete _entity_manager;
  delete _map;
  delete _background;
}

State *BombermanDuo::update()
{
  E_INPUT in = _core->receiver->lastKey();
  if (_running)
    {
      if (in == K_ESCAPE)
	return (new MainMenu());
      if (_p1->isAlive() == false
	  || _p2->isAlive() == false)
	{
	  _running = false;
	  _time_end = _core->getTimeMs();
        }
      _entity_manager->update();
    }
  else
    {
      if (_time_end < _core->getTimeMs() - WAIT_AFTER_DEATH)
	{
	  if (_p1->isAlive())
	    return (new DuoEndMenu(1));
	  else
	    return (new DuoEndMenu(2));
	}
    }
  return (nullptr);
}

void BombermanDuo::spawnBoxes()
{
  std::vector<AEntity*> in_range;

  for (int y = 0; y < _map->getHeight(); y += 1)
    for (int x = 0; x < _map->getWidth(); x += 1)
      {
	if (_map->get(x, y) == M_EMPTY)
	  {
	    in_range = _entity_manager->getInRange(Map::getAbs(x, y), UNIT * 2, "player:npc");
	    if (in_range.size() <= 0
		&& RAND_PERCENT(WALL_CHANCE))
	      _entity_manager->addEntityMap<Box>(x, y);
	  }
      }
}

void BombermanDuo::begin(Core* core)
{
  _core = core;
  _map = new Map(_core, SETTINGS.map_size, SETTINGS.map_size);
  _entity_manager = new	EntityManager(_core, _map);


  _background = new Image(core,
			  core->video->getTexture((char*)"./res/background.png"),
			  irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT * 0.86));
  
  
  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;

  _core->cam->setPosition(irr::core::vector3df(width / 4, width, height / 2));
  _core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  //_entity_manager->addEntity<Bomb>(irr::core::vector3df(3 * UNIT, 0, 3 * UNIT));
  _p1 = _entity_manager->addEntityMap<Player1>(1, 1);
  _p2 = _entity_manager->addEntityMap<Player2>(_map->getWidth() - 2, _map->getHeight() - 2);
  _entity_manager->update();
  //_entity_manager->addEntityMap<Box>(3, 2);
  this->spawnBoxes();
}
