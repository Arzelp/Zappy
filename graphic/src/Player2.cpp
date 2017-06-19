//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Mon Jun  5 20:56:21 2017 arnaud.alies
//

#include "Player2.hpp"
#include "EntityManager.hpp"
#include "Bomb.hpp"

Player2::Player2()
{
  _id = 2;
}

Player2::~Player2()
{
}

void Player2::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomberman/tris.md2",
                   irr::core::vector3df(4, 4, 4),
                   "./res/bomberman/Mexican.pcx");
  _mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
}

EState Player2::getState()
{
  EState res = S_IDLE;

  if (_core->receiver->keyState(K_P2_SPACE))
    res = S_PLANT;
  else if (_core->receiver->keyState(K_P2_UP))
    res = S_RUN_UP;
  else if (_core->receiver->keyState(K_P2_DOWN))
    res = S_RUN_DOWN;
  else if (_core->receiver->keyState(K_P2_LEFT))
    res = S_RUN_LEFT;
  else if (_core->receiver->keyState(K_P2_RIGHT))
    res = S_RUN_RIGHT;
  else
    res = S_IDLE;
  return (res);
}

