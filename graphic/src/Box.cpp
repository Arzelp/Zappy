//
// Boxer.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Mon Jun 19 18:03:12 2017 arnaud.alies
//

#include "Random.hpp"
#include "Map.hpp"
#include "Box.hpp"
#include "EntityManager.hpp"

Box::Box()
{
}

void Box::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
		   "./res/crate/crate1.obj",
		   irr::core::vector3df(1.1, 0.7, 1.1),
		   "./res/crate/T_crate1_D.png");
}

Box::~Box()
{
  int x, y;

  this->getPosMap(&x, &y);
  if (_map->get(x, y) == M_OBS)
    _map->set(x, y, M_EMPTY);
  delete _mesh;
}

void Box::kill()
{
  int x, y;

  //this->getPosMap(&x, &y);
  //AEntity::kill();
}

void Box::update()
{
  /* set map collision */
  int x, y;
  this->getPosMap(&x, &y);
  if (_map->get(x, y) == M_EMPTY)
    _map->set(x, y, M_OBS);
}

void Box::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target);
}

irr::core::vector3df Box::getPos() const
{
  return (_mesh->node->getPosition());
}

std::string Box::getType() const
{
  return ("box");
}
