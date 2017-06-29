//
// ErrorMenu.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu Jun  8 15:32:43 2017 arnaud.alies
// Last update Thu Jun 29 16:27:23 2017 arnaud.alies
//

#include <string>
#include "MainMenu.hpp"
#include "ErrorMenu.hpp"

ErrorMenu::ErrorMenu(std::string message) :
  _core(nullptr),
  _message(message)
{
  _time_end = _core->getTimeMs();
}

ErrorMenu::~ErrorMenu()
{
  delete _background;
  _staticText->remove();
}

State* ErrorMenu::update()
{
  if (_time_end < _core->getTimeMs() - 2500)
    {
      return (new MainMenu());
    }
  return (nullptr);
}

void ErrorMenu::begin(Core* core)
{
  irr::core::stringw text(_message.c_str());
  _core = core;
  _background = new Image(core,
			  core->video->getTexture((char*)"./res/bluescreen.png"),
			  irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT * 0.86));
    
  _staticText = _core->gui->addStaticText(text.c_str(),
					  irr::core::rect<irr::s32>(10,10,300,300),
					  false);
}
