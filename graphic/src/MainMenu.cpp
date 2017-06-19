//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Tue Jun 13 14:50:51 2017 arnaud.alies
//

#include <iostream>
#include "BombermanSolo.hpp"
#include "BombermanDuo.hpp"
#include "MainMenu.hpp"
#include "GameSelectMenu.hpp"
#include "SettingsMenu.hpp"

MainMenu::MainMenu() :
  _core(nullptr),
  _img(nullptr),
  _list(nullptr)
{
}

MainMenu::~MainMenu()
{
  delete _list;
  delete _img;
  delete _bomb_left;
  delete _bomb_right;
}

State *MainMenu::update()
{
  E_INPUT in;
  in = _core->receiver->lastKey();
  if (in == K_RIGHT)
    _list->next();
  else if (in == K_LEFT)
    _list->prev();
  else if (in == K_SPACE)
    {
      if (_list->selected() == 0)
	return (new GameSelectMenu());
      if (_list->selected() == 1)
	return (new SettingsMenu());
      if (_list->selected() == 2)
	_core->stop();
    }
  /* rotation */
  irr::core::vector3df rot;
  
  rot = _bomb_left->node->getRotation();
  _bomb_left->node->setRotation(rot + irr::core::vector3df(1, 1.5, 0.2));
  rot = _bomb_right->node->getRotation();
  _bomb_right->node->setRotation(rot + irr::core::vector3df(1.5, 1, 0.2));
  return (nullptr);
}

void	MainMenu::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100, 0, 0));
  _core->cam->setTarget(irr::core::vector3df(0, 0, 0));

  _list = new List(core,
		   irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 1.2),
		   irr::core::position2d<irr::s32>(60, 0));
  _list->addButton("./res/play.png", "./res/iplay.png");
  _list->addButton("./res/setting.png", "./res/isetting.png");
  _list->addButton("./res/exit.png", "./res/iexit.png");
  _list->update();
  _img = new Image(core,
		   core->video->getTexture((char*)"./res/benladen.png"),
		   irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 4));
  _bomb_left = new Mesh(_core,
			"./res/bomb/Bomb.obj",
			irr::core::vector3df(80,80,80),
			"./res/bomb/Albedo.png");
  _bomb_right = new Mesh(_core,
			 "./res/bomb/Bomb.obj",
			 irr::core::vector3df(80,80,80),
			 "./res/bomb/Albedo.png");
  
  _bomb_left->node->setPosition(irr::core::vector3df(0, 0, 60));
  _bomb_right->node->setPosition(irr::core::vector3df(0, 0, -60));
}
