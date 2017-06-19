//
// Random.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Fri Jun 16 10:35:59 2017 arnaud.alies
// Last update Fri Jun 16 10:42:32 2017 arnaud.alies
//

#ifndef RANDOM_HPP_
#define RANDOM_HPP_

class Random
{
public:
  static int randint(int min, int max);
};

#define RAND_PERCENT(x) (Random::randint(0, 100) < (x))

#endif
