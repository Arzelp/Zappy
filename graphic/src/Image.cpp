//
// ImageButton.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 16:54:24 2017 arnaud.alies
// Last update Tue May 23 17:57:24 2017 arnaud.alies
//

#include <stdexcept>
#include "Image.hpp"

Image::Image(Core *core,
	     irr::video::ITexture* texture,
	     irr::core::position2d<irr::s32> pos) :
  _texture(texture),
  _core(core),
  _image(nullptr)
{
  irr::core::dimension2d<irr::u32> dim;
  irr::core::position2d<irr::s32> real_pos;

  if (_texture == nullptr)
    throw std::runtime_error("Invalid texture");

  dim = _texture->getSize();
  real_pos.X = pos.X - (dim.Width / 2);
  real_pos.Y = pos.Y - (dim.Width / 2);
  _image = _core->gui->addImage(_texture, real_pos);
  if (_image == nullptr)
    throw std::runtime_error("Error loading texture");
}

Image::~Image()
{
  _image->remove();
}
