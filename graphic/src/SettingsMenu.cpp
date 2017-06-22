//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Thu Jun 22 10:11:03 2017 arnaud.alies
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
  _back_button->remove();
}

State* SettingsMenu::update()
{
  E_INPUT in;
  in = _core->receiver->lastKey();
  if (in == K_ESCAPE || _back_button->isPressed())
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
					     Core::getDim(0.2, 30),
					     false);
  
  _scrollbar = _core->gui->addScrollBar(true, Core::getDim(0.2, 80));
  _scrollbar->setMin(9);
  _scrollbar->setMax(19);
  _scrollbar->setSmallStep(1);
  _scrollbar->setPos(SETTINGS.map_size);
  _core->gui->setFocus(_scrollbar);

  _music_text = _core->gui->addStaticText(irr::core::stringw("Music").c_str(),
					  Core::getDim(0.2, 120),
					  false);
  _music_checkbox = _core->gui->addCheckBox(SETTINGS.music, Core::getDim(0.4, 140));
  _back_button = _core->gui->addButton(Core::getDim(0.2, HEIGHT * 0.8),
				       0, -1,
				       irr::core::stringw("back").c_str());

}
