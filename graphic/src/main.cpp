//
// main.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May  2 15:10:14 2017 arnaud.alies
// Last update Wed Jun 21 14:12:02 2017 arnaud.alies
//

#include <iostream>
#include "Indie.h"
#include "Core.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

void test()
{
 sf::SoundBuffer buffer;
  if (!buffer.loadFromFile("./res/sounds/explosion.ogg"))
    return ;
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
}

int	main()
{
  Core	core;
  
  core.run();
  return (0);
}
