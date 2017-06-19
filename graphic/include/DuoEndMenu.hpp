//
// DuoEndMenu.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun  6 16:07:18 2017 arnaud.alies
// Last update Wed Jun  7 18:24:29 2017 arnaud.alies
//

#ifndef DUOENDMENU_HPP_
#define DUOENDMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "Image.hpp"
#include "List.hpp"

class DuoEndMenu : public State
{
private:
  List* _list;
  Image* _img;
  Core* _core;
  int _sel;
public:
  DuoEndMenu(int);
  virtual ~DuoEndMenu();
  State *update();
  void begin(Core*);
};

#endif
