//
// Map.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 13:46:12 2017 arnaud.alies
// Last update Wed Jun 21 13:08:36 2017 arnaud.alies
//

#include <iostream>
#include "Map.hpp"

irr::core::vector3df Map::getAbs(int x, int y)
{
  return (irr::core::vector3df(x * UNIT, 0, y * UNIT));
}

int Map::getX(irr::core::vector3df pos)
{
  return ((pos.X + UNIT / 2) / UNIT);
}

int Map::getY(irr::core::vector3df pos)
{
  return ((pos.Z + UNIT / 2) / UNIT);
}

void Map::set(int x, int y, EMap block)
{
  _map.at(x + (y * _width)) = block;
}

void Map::initMap()
{
  for (int y = 0; y < _height; y += 1)
    for (int x = 0; x < _width; x += 1)
      {
	/*
        if (x % 2 == 0
	    && y % 2 == 0)
          _map.push_back(M_WALL);
	else if (x == 0
		 || x == _width - 1
		 || y == 0
		 || y == _height - 1)
	  _map.push_back(M_WALL);
        else
	*/
	_map.push_back(M_EMPTY);
      }
}

Mesh* Map::newWall(int x, int y)
{
  Mesh *buff = new Mesh(_core,
			"./res/crate/crate1.obj",
			irr::core::vector3df(1.1,0.7,1.1),
			"./res/crate/solid_dark.png");
  buff->node->setPosition(Map::getAbs(x, y));
  return (buff);
}

Mesh* Map::newFloor(int x, int y)
{
  Mesh *buff = new Mesh(_core,
			"./res/floor/Sci-Fi-Floor-1-OBJ.obj",
			irr::core::vector3df(52,52,52),
			"./res/floor/floor.png");
  buff->node->setPosition(Map::getAbs(x, y));
  return (buff);
}

Map::Map(Core* core, int width, int height) :
  _core(core),
  _width(width),
  _height(height)
{
  this->initMap();
  this->update();
}

Map::~Map()
{
  this->clear();
}

void Map::clear()
{
  for (auto mesh : _static_meshes)
    {
      //nullptr ?!
      delete mesh;
    }
  _static_meshes.clear();
}

void Map::update()
{
  this->clear();
  for (int y = 0; y < _height; y += 1)
    for (int x = 0; x < _width; x += 1)
      {
	if (this->get(x, y) == M_WALL)
	  {
	    _static_meshes.push_back(this->newWall(x, y));
	 }
	else
          {
	    _static_meshes.push_back(this->newFloor(x, y));
          }
      }
}

int Map::getWidth() const
{
  return (_width);
}

int Map::getHeight() const
{
  return (_height);
}

EMap Map::get(int x, int y) const
{
  return (_map.at(x + y * _width));
}

void Map::print() const
{
  for (int y = 0; y < _height; y += 1)
    {
      for (int x = 0; x < _width; x += 1)
      {
	if (this->get(x, y))
	  std::cout << "X";
	else
	  std::cout << " ";
      }
      std::cout << std::endl;
    }
}

irr::core::vector3df Map::getValidPos(irr::core::vector3df pos, irr::core::vector3df dir) const
{
  irr::core::vector3df res;
  int int_dir;
  
  res.Y = pos.Y;
  if (dir.X != 0)
    {
      int_dir = (dir.X > 0 ? 1 : -1);
      res.Z = Map::getAbs(0, Map::getY(pos)).Z;
      if (this->get(Map::getX(pos + irr::core::vector3df(int_dir * (UNIT / 2), 0, 0)),
		    Map::getY(pos))
	  != M_EMPTY)
	return (pos);
      res.X = pos.X + dir.X;
    }
  else if (dir.Z != 0)
    {
      int_dir = (dir.Z > 0 ? 1 : -1);
      res.X = Map::getAbs(Map::getX(pos), 0).X;
      if (this->get(Map::getX(pos),
		    Map::getY(pos + irr::core::vector3df(0, 0, int_dir * (UNIT / 2))))
	  != M_EMPTY)
	return (pos);
      res.Z = pos.Z + dir.Z;
    }
  return (res);
}
