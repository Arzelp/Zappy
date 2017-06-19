//
// SoloEndMenu.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu Jun  8 15:32:43 2017 arnaud.alies
// Last update Mon Jun 12 19:20:32 2017 arnaud.alies
//

#include <string>
#include "MainMenu.hpp"
#include "BombermanSolo.hpp"
#include "SoloEndMenu.hpp"

SoloEndMenu::SoloEndMenu(int sel) :
  _core(nullptr),
  _sel(sel)
{
  _time_end = _core->getTimeMs();
}

SoloEndMenu::~SoloEndMenu()
{
  delete _background;
  _staticText->remove();
}

State* SoloEndMenu::update()
{
  if (_time_end < _core->getTimeMs() - 2500)
    {
      if (_sel == 0)
	return (new MainMenu());
      else
	return (new BombermanSolo(_sel + 1));
    }
  return (nullptr);
}

void SoloEndMenu::begin(Core* core)
{
  irr::core::stringw text;
  _core = core;
  if (_sel > 0)
    {
      text = irr::core::stringw(std::string("Level: " + std::to_string(_sel + 1)).c_str());
      _background = new Image(core,
			      core->video->getTexture((char*)"./res/next_level.png"),
			      irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT * 0.86));
    }
  else
    {
      _background = new Image(core,
			      core->video->getTexture((char*)"./res/game_over.png"),
			      irr::core::position2d<irr::s32>(WIDTH / 2, HEIGHT * 0.86));
    }
  _staticText = _core->gui->addStaticText(text.c_str(),
					  irr::core::rect<irr::s32>(10,10,260,50),
					  false);
}
