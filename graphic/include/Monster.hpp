//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Thu Jun 15 16:12:39 2017 arnaud.alies
//

#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include "APlayer.hpp"

class Monster : public APlayer
{
private:
  sf::SoundBuffer _sound_buffer;
  sf::Sound _sound;
public:
  Monster();
  virtual ~Monster();
  void init(Core*, Map*, EntityManager*);
  virtual EState getState();
  bool checkMove(int, int);
  std::string getType() const;
  void update();
};

#endif
