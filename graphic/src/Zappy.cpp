//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Thu Jun 22 10:08:57 2017 arnaud.alies
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
      //_cam->setPos(Map::getAbs(0, 0));
    }
  //
  if (in == K_SPACE)
    {
      //scene::ITriangleSelector* selector;
      
      irr::scene::ISceneCollisionManager* scm = _core->scene->getSceneCollisionManager();
      irr::core::line3d<irr::f32> ray =
	scm->getRayFromScreenCoordinates(_core->device->getCursorControl()->getPosition(),
					 _core->cam);
      irr::core::triangle3df tri;
      irr::core::vector3df col;
      irr::scene::ISceneNode* node = scm->getSceneNodeAndCollisionPointFromRay(ray, col, tri);
      if (node != nullptr)
	_cam->setPosSlow(node->getPosition());
    }
  //
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
  
  int width = _map->getWidth() * UNIT;
  int height = _map->getHeight() * UNIT;

  //_core->cam->setPosition(irr::core::vector3df(width / 4, width, height / 2));
  //_core->cam->setTarget(irr::core::vector3df(width / 2, 0, height / 2));
  
  _cam = _entity_manager->addEntityMap<Camera>(_map->getWidth() / 2, _map->getHeight() / 2);
}
