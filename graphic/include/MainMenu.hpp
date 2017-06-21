//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Wed Jun 21 11:11:39 2017 arnaud.alies
//

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "Image.hpp"
#include "List.hpp"
#include "Mesh.hpp"

class MainMenu : public State
{
private:
  irr::gui::IGUIButton* _start_button;
  irr::gui::IGUIButton* _settings_button;
  irr::gui::IGUIButton* _exit_button;
  Image* _img;
  Core* _core;
public:
  MainMenu();
  virtual ~MainMenu();
  State *update();
  void begin(Core*);
};

#endif
