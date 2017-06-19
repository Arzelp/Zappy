//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Fri Jun 16 10:40:19 2017 arnaud.alies
//

#include "Plane.hpp"
#include "Map.hpp"
#include "EntityManager.hpp"
#include "Bomb.hpp"
#include "Random.hpp"

irr::core::vector3df Plane::getStart(int x, int y)
{
  irr::core::vector3df res = Map::getAbs(x, y);

  res.Y = UNIT * (((float)Random::randint(20, 25)) / 10.0);
  res.Z = -(_map->getHeight() * UNIT);
  return (res);
}

Plane::Plane()
{
  vel = irr::core::vector3df(0, 0, 9) * (((float)Random::randint(1, 30)) / 10.0);
  _first = true;
  _target_x = 0;
  _target_y = 0;
  _plant = false;
  bomb_range = 1;
}

void Plane::init(Core* core, Map* map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/plane/TAL16OBJ.obj",
                   irr::core::vector3df(50, 50, 50),
                   "./res/plane/TALTS.jpg");
  _mesh->node->setRotation(irr::core::vector3df(-90,0,0));
}

Plane::~Plane()
{
  delete _mesh;
}

void Plane::update()
{
  int x, y;
  this->getPosMap(&x, &y);

  if (_first)
    {
      _first = false;
      _target_x = x;
      _target_y = y;
      this->setPos(this->getStart(x, y));
    }
  else
    {
      //if (this->getPos().Z > _map->getHeight() * UNIT * 2)
      if (x == _target_x && y == _target_y && _plant == false)
	{
	  Bomb* bomb = _entity_manager->addEntityMap<Bomb>(x, y);
	  bomb->range = bomb_range;
	  bomb->id = 0;
	  _plant = true;
	  vel += irr::core::vector3df(0,1,0);
	}
      this->setPos(this->getPos() + vel);
      if (y > _map->getWidth() * 2)
	{
	  _entity_manager->queueDeleteEntity(this);
	}
    }
}

void Plane::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target);
}

irr::core::vector3df Plane::getPos() const
{
  return (_mesh->node->getPosition());
}

std::string Plane::getType() const
{
  return ("plane");
}
