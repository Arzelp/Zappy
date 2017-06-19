//
// State.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:30:25 2017 arnaud.alies
// Last update Thu May  4 13:04:27 2017 arnaud.alies
//

#ifndef STATE_HPP_
#define STATE_HPP_

#include "Indie.h"

class Core;

class State
{
public:
  virtual ~State() {};
  virtual void begin(Core*) = 0;
  virtual State *update() = 0;
};

#endif
