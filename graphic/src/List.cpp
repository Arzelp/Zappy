//
// List.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon May 22 11:36:15 2017 arnaud.alies
// Last update Wed Jun 14 11:04:12 2017 arnaud.alies
//

#include "List.hpp"

List::List(Core *core,
	   irr::core::position2d<irr::s32> pos,
	   irr::core::position2d<irr::s32> inc) :
  _core(core),
  _pos(pos),
  _inc(inc)
{
  _selected = 0;
}

List::~List()
{
  this->clear();
  /*
  for (auto texture : _itextures)
    {
      _core->video->removeTexture(texture);
    }
  for (auto texture : _textures)
    {
      _core->video->removeTexture(texture);
    }
  */
}

void List::clear()
{
  while (_images.size() > 0)
    {
      delete _images.at(_images.size() - 1);
      _images.pop_back();
    }
}

void List::render()
{
  irr::core::position2d<irr::s32> pos = _pos;
  irr::video::ITexture* buff;
  int x;

  if (_textures.size() <= 0)
    return ;
  pos -= (_textures.size() * _inc) / 2;
  x = 0;
  while (x < _textures.size())
    {
      if (x == _selected % _textures.size())
	buff = _itextures.at(x);
      else
	buff = _textures.at(x);
      _images.push_back(new Image(_core,
				  buff,
				  pos));
      pos += _inc * 2;
      x += 1;
    }
}

void List::update()
{
  this->clear();
  this->render();
}

bool List::addButton(std::string image, std::string iimage)
{
  irr::video::ITexture* texture = _core->video->getTexture(image.c_str());
  irr::video::ITexture* itexture = _core->video->getTexture(iimage.c_str());

  if (texture == nullptr || itexture == nullptr)
    return (false);
  _itextures.push_back(itexture);
  _textures.push_back(texture);
  return (true);
}

void List::next()
{
  _selected += 1;
  if (_selected >= _textures.size())
    _selected = 0;
  this->update();
}

void List::prev()
{
  _selected -= 1;
  if (_selected < 0)
    _selected = _textures.size() - 1;
  this->update();
}

int	List::selected() const
{
  return (_selected);
}
