//
// Map.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 23 13:13:43 2017 arnaud.alies
// Last update Wed May 31 13:58:01 2017 arnaud.alies
//

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include "Core.hpp"
#include "Mesh.hpp"

#define UNIT (100)

enum EMap
  {
    M_EMPTY = 0,
    M_WALL,
    M_OBS
  };

class Map
{
private:
  Core* _core;
  int _width;
  int _height;
  //std::vector<EMap> _loadedMap;
  std::vector<EMap> _map;
  std::vector<Mesh*> _static_meshes;
  void clear();
protected:
  void initMap();
  Mesh* newWall(int x, int y);
  Mesh* newFloor(int x, int y);
public:
  Map(Core* core, int width, int height);
  virtual ~Map();
  static irr::core::vector3df getAbs(int x, int y);
  static int getX(irr::core::vector3df pos);
  static int getY(irr::core::vector3df pos);
  int getWidth() const;
  int getHeight() const;
  EMap get(int x, int y) const;
  void set(int x, int y, EMap block);
  irr::core::vector3df getValidPos(irr::core::vector3df pos, irr::core::vector3df dir) const;
  void print() const;
  void update();
};

#endif
