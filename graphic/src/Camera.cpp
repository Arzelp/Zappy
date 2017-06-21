//
// Camera.cpp for uhe in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Wed Jun 21 13:17:13 2017 arnaud.alies
// Last update Wed Jun 21 13:55:41 2017 arnaud.alies
//

#include "Camera.hpp"

Camera::Camera()
{
  _offset = irr::core::vector3df(0, CAMERA_OFFSET, 0);
}

Camera::~Camera()
{

}

void Camera::init(Core* core, Map* map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
}

void Camera::update()
{

}

irr::core::vector3df Camera::getPos() const
{
  return (_core->cam->getPosition() - _offset);
}

void Camera::setPos(irr::core::vector3df target)
{
  _core->cam->setPosition(target + _offset);
  _core->cam->setTarget(target);
}

std::string Camera::getType() const
{
  return ("camera");
}
