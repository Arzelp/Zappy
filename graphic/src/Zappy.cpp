//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Thu Jun 22 15:50:58 2017 arnaud.alies
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
  _img = nullptr;
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
  
  if (in == K_SPACE)
    {
      irr::scene::ISceneNode* node = _core->getNodeFromMouse();
      if (node != nullptr)
	{
	  _cam->setPosSlow(node->getPosition());

	  /*
	  irr::core::position2d<irr::s32> pos2d = _core->getViewPos(node->getPosition());
	  delete _img;
	  _img = new Image(_core,
			   _core->video->getTexture((char*)"./res/one.png"),
			   pos2d);
	  */
	}
    }
  
  //Camera move
  if (_core->receiver->keyState(K_UP))
    _cam->move(irr::core::vector3df(1, 0, 0));
  if (_core->receiver->keyState(K_DOWN))
    _cam->move(irr::core::vector3df(-1, 0, 0));
  if (_core->receiver->keyState(K_LEFT))
    _cam->move(irr::core::vector3df(0, 0, 1));
  if (_core->receiver->keyState(K_RIGHT))
    _cam->move(irr::core::vector3df(0, 0, -1));
  
  _entity_manager->update();
  return (nullptr);
}

void Zappy::begin(Core* core)
{
  _core = core;
  _map = new Map(_core, SETTINGS.map_size, SETTINGS.map_size);
  _entity_manager = new	EntityManager(_core, _map);
  
  //int width = _map->getWidth() * UNIT;
  //int height = _map->getHeight() * UNIT;

  //_core->cam->setPosition(irr::core::vector3df(width / 4, width, height / 2));
  //_core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  
  _cam = _entity_manager->addEntityMap<Camera>(_map->getWidth() / 2, _map->getHeight() / 2);
}
