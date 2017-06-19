//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Wed Jun  7 13:10:21 2017 arnaud.alies
//

#ifndef GAMESELECTMENU_HPP_
#define GAMESELECTMENU_HPP_

#include "Indie.h"
#include "Core.hpp"
#include "State.hpp"
#include "Image.hpp"
#include "List.hpp"

class GameSelectMenu : public State
{
private:
  List* _list;
  Image* _img;
  Core* _core;
public:
  GameSelectMenu();
  virtual ~GameSelectMenu();
  State *update();
  void begin(Core*);
};

#endif
