//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Mon Jun 19 18:18:25 2017 arnaud.alies
//

#include <iostream>
#include "MainMenu.hpp"
#include "Zappy.hpp"
#include "Box.hpp"
#include "Random.hpp"

Zappy::Zappy() :
  _core(nullptr),
  _entity_manager(nullptr),
  _time_end(0),
  _running(true)
{
}

Zappy::~Zappy()
{
  delete _entity_manager;
  delete _map;
  delete _background;
}

State *Zappy::update()
{
  E_INPUT in = _core->receiver->lastKey();
  if (in == K_ESCAPE)
    return (new MainMenu());
  return (nullptr);
}

void Zappy::spawnBoxes()
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

void Zappy::begin(Core* core)
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
  _entity_manager->update();
  //_entity_manager->addEntityMap<Box>(3, 2);
  //this->spawnBoxes();
}
