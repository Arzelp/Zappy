//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Wed Jun 21 11:36:21 2017 arnaud.alies
//

#include <iostream>
#include "Zappy.hpp"
#include "MainMenu.hpp"
#include "SettingsMenu.hpp"

MainMenu::MainMenu() :
  _core(nullptr),
  _img(nullptr)
{
}

MainMenu::~MainMenu()
{
  delete _img;
  _start_button->remove();
  _settings_button->remove();
  _exit_button->remove();
}

State *MainMenu::update()
{
  if (_start_button->isPressed())
    return (new Zappy());
  else if (_settings_button->isPressed())
    return (new SettingsMenu());
  else if (_exit_button->isPressed())
    _core->stop();
  return (nullptr);
}

void	MainMenu::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100, 0, 0));
  _core->cam->setTarget(irr::core::vector3df(0, 0, 0));

  
  _img = new Image(core,
		   core->video->getTexture((char*)"./res/doggo.png"),
		   irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT / 3));

  int off = HEIGHT / 1.5;
  _start_button = _core->gui->addButton(SettingsMenu::getDim(0.3, off),
					0, -1,
					irr::core::stringw("Start").c_str());
  _settings_button = _core->gui->addButton(SettingsMenu::getDim(0.3, off + 50),
					   0, -1,
					   irr::core::stringw("Settings").c_str());
  _exit_button = _core->gui->addButton(SettingsMenu::getDim(0.3, off + 100),
				       0, -1,
				       irr::core::stringw("Exit").c_str());
}
