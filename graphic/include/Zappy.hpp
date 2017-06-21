//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Wed Jun 21 11:50:52 2017 arnaud.alies
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

#define WAIT_AFTER_DEATH (1200)

class Zappy : public State
{
protected:
  Map* _map;
  Core* _core;
  EntityManager* _entity_manager;
  bool _running;
  int _time_end;
public:
  Zappy();
  virtual ~Zappy();
  State* update();
  void begin(Core*);
  void spawnBoxes();
};

#endif
