//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Thu Jun  8 18:04:06 2017 arnaud.alies
//

#include <iostream>
#include "Welcome.hpp"
#include "MainMenu.hpp"

Welcome::Welcome()
{
  _stime = Core::getTime();
  _core = nullptr;
}

Welcome::~Welcome()
{
  delete _bomb;
}

State *Welcome::update()
{
  int ctime = Core::getTime();
  State *res = nullptr;
  irr::core::vector3df rot;

  rot = _bomb->node->getRotation();
  _bomb->node->setRotation(rot + irr::core::vector3df(1,1,0));
  if (ctime > _stime + DURATION)
    res = new MainMenu();
  _core->cam->setPosition(_core->cam->getPosition() - irr::core::vector3df(0.6,0,0));
  return (res);
}

void Welcome::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100,0,0));
  _core->cam->setTarget(irr::core::vector3df(0,0,0));
  _bomb = new Mesh(_core,
		   "./res/bomb/Bomb.obj",
		   irr::core::vector3df(50,50,50),
		   "./res/bomb/Albedo.png");
}
