//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Wed Jun 21 11:00:11 2017 arnaud.alies
//

#include "SettingsMenu.hpp"
#include "MainMenu.hpp"

SettingsMenu::SettingsMenu() :
  _core(nullptr)
{
}

SettingsMenu::~SettingsMenu()
{
  _scrollbar->setEnabled(false);
  _scrollbar->remove();
  _map_size_text->remove();
  _music_checkbox->setEnabled(false);
  _music_checkbox->remove();
  _music_text->remove();
}

State *SettingsMenu::update()
{
  E_INPUT in;
  in = _core->receiver->lastKey();
  if (in == K_ESCAPE)
    return (new MainMenu());
  SETTINGS.map_size = _scrollbar->getPos();
  if (SETTINGS.map_size % 2 == 0)
    SETTINGS.map_size += 1;
  if (_music_checkbox->isChecked() && SETTINGS.music == false)
    {
      _core->sound.play();
      SETTINGS.music = true;
    }
  else if (_music_checkbox->isChecked() == false && SETTINGS.music == true)
    {
      _core->sound.stop();
      SETTINGS.music = false;
    }
  return (nullptr);
}

irr::core::rect<irr::s32> SettingsMenu::getDim(float margin, int pos, int height)
{
  irr::core::rect<irr::s32> res;

  res = irr::core::rect<irr::s32>(WIDTH * margin, pos,
				  WIDTH * (1.0 - margin), pos + height);
  return (res);
}

void	SettingsMenu::begin(Core* core)
{
  _core = core;
  _core->cam->setPosition(irr::core::vector3df(100, 0, 0));
  _core->cam->setTarget(irr::core::vector3df(0, 0, 0));

  /*
  _core->gui->addEditBox(irr::core::stringw("").c_str(),
			 irr::core::rect<irr::s32>(10, 10, 500, 500));
  */
  _map_size_text = _core->gui->addStaticText(irr::core::stringw("Map size").c_str(),
					     SettingsMenu::getDim(0.2, 30),
					     false);
  
  _scrollbar = _core->gui->addScrollBar(true, SettingsMenu::getDim(0.2, 80));
  _scrollbar->setMin(9);
  _scrollbar->setMax(19);
  _scrollbar->setSmallStep(1);
  _scrollbar->setPos(SETTINGS.map_size);
  _core->gui->setFocus(_scrollbar);

  _music_text = _core->gui->addStaticText(irr::core::stringw("Music").c_str(),
					  SettingsMenu::getDim(0.2, 120),
					  false);

  _music_checkbox = _core->gui->addCheckBox(SETTINGS.music, SettingsMenu::getDim(0.4, 140));
}
