//
// HudText.hpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun 27 14:46:59 2017 arnaud.alies
// Last update Wed Jun 28 10:32:41 2017 arnaud.alies
//

#ifndef HUDTEXT_HPP_
#define HUDTEXT_HPP_

#include "Indie.h"
#include "Core.hpp"

class HudText
{
protected:
  irr::scene::IBillboardTextSceneNode *_billboard_text;
  irr::scene::IBillboardSceneNode *_billboard;
  std::string _text;
  irr::core::vector3df _pos;
  int _size;
  Core* _core;
public:
  HudText(Core* core, std::string text, int size = 25);
  virtual ~HudText();
  void setPos(irr::core::vector3df pos);
  irr::core::vector3df getPos();
  void setText(std::string text);
};

#endif
