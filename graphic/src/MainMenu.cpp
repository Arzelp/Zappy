//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Fri Jun 30 18:43:44 2017 arnaud.alies
//

#include <iostream>
#include "Zappy.hpp"
#include "MainMenu.hpp"
#include "SettingsMenu.hpp"

MainMenu::MainMenu() :
  _core(nullptr),
  _img(nullptr)
{
  _host = "127.0.0.1";
  _port = "4242";
}

MainMenu::~MainMenu()
{
  delete _img;
  _start_button->remove();
  _settings_button->remove();
  _exit_button->remove();
  _host_box->setEnabled(false);
  _host_box->remove();
  _host_text->remove();
  _port_box->setEnabled(false);
  _port_box->remove();
  _port_text->remove();
}

State *MainMenu::update()
{
  std::string port;
  std::string host;
  const wchar_t* charw;
  charw = _host_box->getText();
  for (int x = 0; charw[x] != '\0'; x += 1)
    host += static_cast<char>(charw[x]);
  charw = _port_box->getText();
  for (int x = 0; charw[x] != '\0'; x += 1)
    port += static_cast<char>(charw[x]);
  
  if (_start_button->isPressed())
    return (new Zappy(host, port));
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
  int off = HEIGHT / 2.0;
  _host_text = _core->gui->addStaticText(irr::core::stringw("Host:").c_str(),
					 Core::getDim(0.3, off),
					 false);
  _host_box = _core->gui->addEditBox(irr::core::stringw(_host.c_str()).c_str(),
				     Core::getDim(0.3, off + 40));
  _port_text = _core->gui->addStaticText(irr::core::stringw("Port:").c_str(),
					 Core::getDim(0.3, off + 80),
					 false);
  _port_box = _core->gui->addEditBox(irr::core::stringw(_port.c_str()).c_str(),
				     Core::getDim(0.3, off + 120));
  _start_button = _core->gui->addButton(Core::getDim(0.3, off + 160),
					0, -1,
					irr::core::stringw("Start").c_str());
  _settings_button = _core->gui->addButton(Core::getDim(0.3, off + 200),
					   0, -1,
					   irr::core::stringw("Settings").c_str());
  _exit_button = _core->gui->addButton(Core::getDim(0.3, off + 240),
				       0, -1,
				       irr::core::stringw("Exit").c_str());
}
