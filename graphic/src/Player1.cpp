//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Tue Jun  6 14:24:40 2017 arnaud.alies
//

#include "Player1.hpp"
#include "EntityManager.hpp"
#include "Bomb.hpp"

Player1::Player1()
{
  _id = 1;
}

Player1::~Player1()
{
}

void Player1::init(Core* core, Map *map, EntityManager* entity_manager)
{
  APlayer::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomberman/tris.md2",
                   irr::core::vector3df(4, 4, 4),
                   "./res/bomberman/Bomber.PCX");
  _mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
}

EState Player1::getState()
{
  EState res = S_IDLE;

  if (_core->receiver->keyState(K_SPACE))
    res = S_PLANT;
  else if (_core->receiver->keyState(K_UP))
    res = S_RUN_UP;
  else if (_core->receiver->keyState(K_DOWN))
    res = S_RUN_DOWN;
  else if (_core->receiver->keyState(K_LEFT))
    res = S_RUN_LEFT;
  else if (_core->receiver->keyState(K_RIGHT))
    res = S_RUN_RIGHT;
  else
    res = S_IDLE;
  return (res);
}

