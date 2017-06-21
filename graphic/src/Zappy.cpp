//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Wed Jun 21 15:27:34 2017 arnaud.alies
//

#include <iostream>
#include "MainMenu.hpp"
#include "Zappy.hpp"
#include "Box.hpp"
#include "Random.hpp"

Zappy::Zappy() :
  _core(nullptr),
  _entity_manager(nullptr)
{
}

Zappy::~Zappy()
{
  delete _entity_manager;
  delete _map;
}

State *Zappy::update()
{
  E_INPUT in = _core->receiver->lastKey();

  if (in == K_ESCAPE)
    return (new MainMenu());
  if (in == K_UP)
    {
      _cam->setPos(Map::getAbs(0, 0));
    }
  _entity_manager->update();
  return (nullptr);
}

void Zappy::begin(Core* core)
{
  _core = core;
  _map = new Map(_core, SETTINGS.map_size, SETTINGS.map_size);
  _entity_manager = new	EntityManager(_core, _map);
  
  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;

  //_core->cam->setPosition(irr::core::vector3df(width / 4, width, height / 2));
  //_core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  
  _cam = _entity_manager->addEntityMap<Camera>(_map->getWidth() / 2, _map->getHeight() / 2);
}
