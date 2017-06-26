//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Mon Jun 26 14:02:09 2017 arnaud.alies
//

#include "SettingsMenu.hpp"
#include "MainMenu.hpp"

SettingsMenu::SettingsMenu() :
  _core(nullptr)
{
}

SettingsMenu::~SettingsMenu()
{
  _music_text->remove();
  _music_checkbox->setEnabled(false);
  _music_checkbox->remove();
  _back_button->setEnabled(false);
  _back_button->remove();
}

State* SettingsMenu::update()
{
  E_INPUT in;
  in = _core->receiver->lastKey();
  if (in == K_ESCAPE || _back_button->isPressed())
    return (new MainMenu());
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
  
  _music_text = _core->gui->addStaticText(irr::core::stringw("Music").c_str(),
					  Core::getDim(0.2, 120),
					  false);
  _music_checkbox = _core->gui->addCheckBox(SETTINGS.music, Core::getDim(0.4, 140));
  _back_button = _core->gui->addButton(Core::getDim(0.2, HEIGHT * 0.8),
				       0, -1,
				       irr::core::stringw("back").c_str());

}
