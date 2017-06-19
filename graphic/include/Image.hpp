//
// ImageButton.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 16:23:11 2017 arnaud.alies
// Last update Mon May 22 16:33:16 2017 arnaud.alies
//

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <string>
#include "Indie.h"
#include "Core.hpp"

class Image
{
protected:
  Core *_core;
  irr::video::ITexture *_texture;
  irr::gui::IGUIImage *_image;
public:
  Image(Core*,
	irr::video::ITexture*,
	irr::core::position2d<irr::s32>);
  virtual ~Image();
};

#endif
