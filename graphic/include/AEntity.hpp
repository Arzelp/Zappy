//
// Entity.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Fri May 26 10:41:20 2017 arnaud.alies
// Last update Sun Jun  4 10:56:24 2017 arnaud.alies
//

#ifndef AENTITY_HPP_
#define AENTITY_HPP_

#include "Indie.h"
#include "Map.hpp"
#include "Core.hpp"
#include "EntityManager.hpp"

class AEntity
{
protected:
  Core* _core;
  Map* _map;
  EntityManager* _entity_manager;
public:
  AEntity();
  virtual ~AEntity() {};
  virtual void init(Core* core, Map* map, EntityManager* entity_manager);
  //pure virtual:
  virtual void setPos(irr::core::vector3df target) = 0;
  virtual void getPosMap(int *x, int *y) const;
  virtual irr::core::vector3df getPos() const = 0;
  virtual void update() = 0;
  virtual std::string getType() const;
  virtual void kill();
};

#endif
