//
// SoloEndMenu.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu Jun  8 15:33:00 2017 arnaud.alies
// Last update Thu Jun 29 16:10:57 2017 arnaud.alies
//

#ifndef ERRORMENU_HPP_
#define ERRORMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "Image.hpp"
#include "State.hpp"

class ErrorMenu : public State
{
protected:
  Core* _core;
  int _time_end;
  std::string _message;
public:
  Image* _background;
  irr::gui::IGUIStaticText* _staticText;
public:
  ErrorMenu(std::string message);
  virtual ~ErrorMenu();
  void begin(Core*);
  State *update();
};

#endif
