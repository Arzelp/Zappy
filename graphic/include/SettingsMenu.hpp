//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Wed Jun 21 13:55:50 2017 arnaud.alies
//

#ifndef SETTINGSMENU_HPP_
#define SETTINGSMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "Image.hpp"
#include "Mesh.hpp"

class SettingsMenu : public State
{
private:
  Core* _core;
  irr::gui::IGUIStaticText* _map_size_text;
  irr::gui::IGUIScrollBar* _scrollbar;
  irr::gui::IGUIStaticText* _music_text;
  irr::gui::IGUICheckBox* _music_checkbox;
  irr::gui::IGUIButton* _back_button;
public:
  SettingsMenu();
  virtual ~SettingsMenu();
  State *update();
  void begin(Core*);
  static irr::core::rect<irr::s32> getDim(float margin, int pos, int height = 25);
};

#endif
