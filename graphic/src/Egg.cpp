//
// Egg.cpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon Jun 26 14:09:25 2017 arnaud.alies
// Last update Mon Jun 26 15:03:14 2017 arnaud.alies
//

#include "Egg.hpp"

Egg::Egg() :
  id(0),
  _mesh(nullptr),
  _offset(irr::core::vector3df(0, 0, 0))
{
  
}

Egg::~Egg()
{
  delete _mesh;
}


void Egg::kill()
{
  AEntity::kill();
}

void Egg::init(Core* core, Map* map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/egg/egg.obj",
                   irr::core::vector3df(1, 1, 1),
                   "");
}

void Egg::update()
{

}

void Egg::setPos(irr::core::vector3df target)
{
  return (_mesh->node->setPosition(target + _offset));
}

irr::core::vector3df Egg::getPos() const
{
  return (_mesh->node->getPosition() - _offset);
}

std::string Egg::getType()
{
  return ("egg");
}
