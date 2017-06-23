//
// Resources.cpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu Jun 22 17:07:19 2017 arnaud.alies
// Last update Fri Jun 23 17:07:18 2017 arnaud.alies
//

#include <vector>
#include "Resources.hpp"

Resources::Resources() :
  _scale(0.2),
  _offset(irr::core::vector3df(0, 0, 0))
  //_food(nullptr)
{

}

Resources::~Resources()
{
  for (int x = 0; x < R_SIZE; x += 1)
    delete _meshes[x];
  //delete _food;
}

void Resources::init(Core* core, Map* map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  std::vector<std::string> textures = {"blue.png",
				       "cyan.png",
				       "green.png",
				       "pink.png",
				       "purple.png",
				       "red.png",
				       "yellow.png"};
  for (int x = 0; x < R_SIZE; x += 1)
    _values[x] = 0;
  for (int x = 0; x < R_SIZE; x += 1)
    {
      _meshes[x] = new Mesh(_core,
			    "./res/crate/crate1.obj",
			    irr::core::vector3df(_scale, 0, _scale),
			    "./res/resources/" + textures.at(x));
    }
}

void Resources::update()
{
  float diff_scale;
  irr::core::vector3df target_scale;
  
  for (int x = 0; x < R_SIZE; x += 1)
    {
      diff_scale = ((_values[x] * _scale) - _meshes[x]->node->getScale().Y) / R_EFFECT_SPEED;
      target_scale = irr::core::vector3df(_scale,
				    _meshes[x]->node->getScale().Y + diff_scale,
				    _scale);
      _meshes[x]->node->setScale(target_scale);
    }
  /*
  _food->node->setScale(irr::core::vector3df(_scale,
					     _scale,
					     _scale));
  */
}

irr::core::vector3df Resources::getPos() const
{
  return (_pos);
}

void Resources::setPos(irr::core::vector3df t)
{
  int space = 30;
  int x_off = -UNIT / 1.5;
  int z_off = -UNIT / 1.5;

  _pos = t;
  // cassez pas les couilles mdr
  for (int x = 0; x < R_SIZE; x += 1)
    {
      if (x % 3 == 0)
	{
	  x_off = -UNIT / 1.5;
	  z_off += space;
	}
      x_off += space;
      _meshes[x]->node->setPosition(t + _offset + irr::core::vector3df(x_off,
								       0,
								       z_off));
    }
}

void Resources::setValues(int* values)
{
  for (int x = 0; x < R_SIZE; x += 1)
    _values[x] = values[x];
  /*
  for (int x = 0; x < R_SIZE; x += 1)
    {
      _meshes[x]->node->setScale(irr::core::vector3df(_scale,
						      _scale * values[x],
						      _scale));
    }
  */
}

std::string Resources::getType() const
{
  return ("resources");
}
