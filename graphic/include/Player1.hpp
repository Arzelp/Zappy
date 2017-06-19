//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Tue Jun  6 14:27:19 2017 arnaud.alies
//

#ifndef PLAYERONE_HPP_
#define PLAYERONE_HPP_

#include "APlayer.hpp"

class Player1 : public APlayer
{
public:
  Player1();
  virtual ~Player1();
  void init(Core*, Map*, EntityManager*);
  virtual EState getState();
};

#endif
