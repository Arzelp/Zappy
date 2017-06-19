//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Tue Jun  6 14:26:59 2017 arnaud.alies
//

#ifndef PLAYERTWO_HPP_
#define PLAYERTWO_HPP_

#include "APlayer.hpp"

class Player2 : public APlayer
{
public:
  Player2();
  virtual ~Player2();
  void init(Core*, Map*, EntityManager*);
  virtual EState getState();
};

#endif
