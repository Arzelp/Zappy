//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Sat Jun 24 21:43:23 2017 arnaud.alies
//

#ifndef ZAPPY_HPP_
#define ZAPPY_HPP_

#include <vector>
#include "Indie.h"
#include "Core.hpp"
#include "Map.hpp"
#include "State.hpp"
#include "EntityManager.hpp"
#include "AEntity.hpp"
#include "Image.hpp"
#include "Camera.hpp"
#include "Resources.hpp"
#include "Network.hpp"

class Zappy : public State
{
protected:
  bool _running;
  Network* _network;
  Camera* _cam;
  Core* _core;
  EntityManager* _entity_manager;
  Map* _map;
  //
  Image* _img;
public:
  Zappy();
  virtual ~Zappy();
  State* update();
  void begin(Core*);
  void spawnResources();
  Resources* getResourcesAt(irr::core::vector3df pos);
  //
  void recv_msz(int width, int height);
};

#endif
