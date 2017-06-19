//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Mon Jun 12 15:21:08 2017 arnaud.alies
//

#include "Gate.hpp"
#include "Map.hpp"
#include "EntityManager.hpp"

Gate::Gate()
{
}

void Gate::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/gate/Manhole.obj",
                   irr::core::vector3df(0.1, 0.1, 0.1),
                   "./res/gate/hole.jpg");
}

Gate::~Gate()
{
  delete _mesh;
}

void Gate::update()
{
}

void Gate::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target);
}

irr::core::vector3df Gate::getPos() const
{
  return (_mesh->node->getPosition());
}

std::string Gate::getType() const
{
  return ("gate");
}
