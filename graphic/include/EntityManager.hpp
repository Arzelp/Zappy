//
// EntityManager.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon May 29 10:56:34 2017 arnaud.alies
// Last update Wed Jun  7 14:36:32 2017 arnaud.alies
//

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <vector>
#include "Map.hpp"
#include "Core.hpp"

class AEntity;

class EntityManager
{
protected:
  Map* _map;
  Core* _core;
public:
  std::vector<AEntity*> _entities;
  std::vector<AEntity*> _to_delete;
  std::vector<AEntity*> _to_add;
public:
  EntityManager(Core* core, Map* map);
  virtual ~EntityManager();
  void update();
  template<class T>
  T* addEntity(irr::core::vector3df pos);
  template<class T>
  T* addEntityMap(int x, int y);
  void deleteEntity(AEntity*); /* Warning unsafe to use inside entities */
  void queueDeleteEntity(AEntity*); /* safe to use inside entities */
  std::vector<AEntity*> getInRange(irr::core::vector3df pos,
				   float range,
				   std::string type = "entity");
  std::vector<AEntity*> getAll(std::string type);
  bool exists(AEntity* ent);
  AEntity* getClosestEntity(irr::core::vector3df pos, std::string type, AEntity *ignore = nullptr);
};

template<class T>
T* EntityManager::addEntity(irr::core::vector3df pos)
{
  T* ent;

  ent = new T();
  ent->init(_core, _map, this);
  ent->setPos(pos);
  _to_add.push_back(ent);
  return (ent);
}

template<class T>
T* EntityManager::addEntityMap(int x, int y)
{
  return (this->addEntity<T>(Map::getAbs(x, y)));
}

#endif
