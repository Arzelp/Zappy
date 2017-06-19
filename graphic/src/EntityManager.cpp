//
// EntityManager.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 09:56:46 2017 arnaud.alies
// Last update Wed Jun  7 16:56:56 2017 arnaud.alies
//

#include <sstream>
#include <string>
#include "EntityManager.hpp"
#include "AEntity.hpp"

EntityManager::EntityManager(Core* core, Map* map) :
  _core(core),
  _map(map)
{
}

EntityManager::~EntityManager()
{
  for (auto entity : _to_delete)
    {
      delete entity;
    }
  for (auto entity : _to_add)
    {
      delete entity;
    }
  for (auto entity : _entities)
    {
      delete entity;
    }
}

void EntityManager::update()
{
  for (auto entity : _entities)
    {
      entity->update();
    }
  for (auto entity : _to_delete)
    {
      deleteEntity(entity);
    }
  _entities.insert(_entities.end(), _to_add.begin(), _to_add.end());
  _to_add.clear();
  _to_delete.clear();
}

void EntityManager::deleteEntity(AEntity* entity)
{
  AEntity *ent;
  auto i = std::begin(_entities);
  
  while (i != std::end(_entities))
    {
      ent = *i;
      if (ent == entity)
        {
          i = _entities.erase(i);
          delete ent;
        }
      else
        ++i;
    }
}

void EntityManager::queueDeleteEntity(AEntity* entity)
{
  _to_delete.push_back(entity);
}

std::vector<AEntity*> EntityManager::getAll(std::string type)
{
  std::vector<AEntity*> res;
  std::stringstream type_str(type);
  std::string segment;
  std::vector<std::string> seglist;
  
  while(std::getline(type_str, segment, ':'))
    {
      seglist.push_back(segment);
    }
  for (auto entity : _entities)
    {
      for (auto seg : seglist)
	{
	  if (entity->getType() == seg)
	    res.push_back(entity);
	}
    }
  return (res);
}

std::vector<AEntity*> EntityManager::getInRange(irr::core::vector3df pos,
						float range,
						std::string type)
{
  std::vector<AEntity*> res;
  std::vector<AEntity*> ents = this->getAll(type);

  for (auto entity : ents)
    {
      if (entity->getPos().getDistanceFrom(pos) <= range)
	res.push_back(entity);
    }
  return (res);
}

bool EntityManager::exists(AEntity* ent)
{
  for (auto entity : _entities)
    {
      if (entity == ent)
	return (true);
    }
  return (false);
}

AEntity* EntityManager::getClosestEntity(irr::core::vector3df pos, std::string type, AEntity *ignore)
{
  std::vector<AEntity*> ents = this->getAll(type);;
  AEntity *closestEnt = nullptr;

  for (auto ent : ents)
    {
      if (closestEnt == nullptr)
	closestEnt = ent;
      else if (ent != ignore)
	{
	  if (ent->getPos().getDistanceFrom(pos) < closestEnt->getPos().getDistanceFrom(pos))
	    closestEnt = ent;
	}
    }
  return (closestEnt);
}
