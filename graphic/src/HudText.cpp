//
// HudText.cpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun 27 14:58:50 2017 arnaud.alies
// Last update Tue Jun 27 16:05:44 2017 arnaud.alies
//

#include "HudText.hpp"

HudText::HudText(Core* core, std::string text, int size) :
  _core(core)
{
  irr::core::dimension2d<irr::f32> dim;

  _text = text;
  _size = size;
  dim.Width = _size * text.length();
  dim.Height = _size * 2;
  _billboard_text =
    _core->scene->addBillboardTextSceneNode(_core->font,
                                            irr::core::stringw(text.c_str()).c_str(),
                                            0,
                                            dim);
  _billboard = _core->scene->addBillboardSceneNode(0,
                                                   dim,
                                                   irr::core::vector3df(0, 0, 0),
                                                   0,
                                                   0x55000000,
                                                   0x55000000);
  _billboard->setMaterialType(irr::video::EMT_TRANSPARENT_VERTEX_ALPHA);
  _billboard->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

HudText::~HudText()
{
  _billboard->remove();
  _billboard_text->remove();
}

void HudText::setPos(irr::core::vector3df pos)
{
  _billboard->setPosition(pos);
  _billboard_text->setPosition(pos);
  _pos = pos;
}

irr::core::vector3df HudText::getPos()
{
  return (_pos);
}

void HudText::setText(std::string text)
{
  irr::core::dimension2d<irr::f32> dim;

  dim.Width = _size * text.length();
  dim.Height = _size * 2;
  _text = text;
  _billboard_text->setText(irr::core::stringw(text.c_str()).c_str());
  _billboard_text->setSize(dim);
  _billboard->setSize(dim);
}
