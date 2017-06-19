//
// random.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun Jun  4 16:03:13 2017 arnaud.alies
// Last update Fri Jun 16 14:17:01 2017 arnaud.alies
//

#include <cstdlib>
#include "Random.hpp"
#include "Core.hpp"

int Random::randint(int min, int max)
{
  /*
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
  return (dist(rng));
  */
  static unsigned int seed = (unsigned int)Core::getTimeMs();
  int res;

  std::srand(seed);
  seed += 1;
  res = ((std::rand() % (max - min + 1)) + min);
  return (res);
}
