//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Fri Jun 30 18:39:43 2017 arnaud.alies
//

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "Image.hpp"
#include "Mesh.hpp"

class MainMenu : public State
{
private:
  irr::gui::IGUIButton* _start_button;
  irr::gui::IGUIButton* _settings_button;
  irr::gui::IGUIButton* _exit_button;
  irr::gui::IGUIStaticText* _host_text;
  irr::gui::IGUIEditBox* _host_box;
  irr::gui::IGUIStaticText* _port_text;
  irr::gui::IGUIEditBox* _port_box;
  Image* _img;
  Core* _core;
  std::string _host;
  std::string _port;
public:
  MainMenu();
  virtual ~MainMenu();
  State *update();
  void begin(Core*);
};

#endif
