//
// Camera.cpp for uhe in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Wed Jun 21 13:17:13 2017 arnaud.alies
// Last update Fri Jun 23 16:27:34 2017 arnaud.alies
//

#include "Camera.hpp"

Camera::Camera()
{
  _offset = irr::core::vector3df(CAMERA_OFFSET / 3, CAMERA_OFFSET, 0);
  _first = true;
}

Camera::~Camera()
{

}

void Camera::init(Core* core, Map* map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  //check if another camera exists
}

void Camera::update()
{
  irr::core::vector3df curr = this->getPos();
  irr::core::vector3df diff = _target - curr;
  irr::core::vector3df move = diff / CAMERA_SPEED;

  this->setPos(curr + move);
}

void Camera::setPosSlow(irr::core::vector3df target)
{
  _target = target;
}

irr::core::vector3df Camera::getPos() const
{
  return (_core->cam->getPosition() - _offset);
}

void Camera::setPos(irr::core::vector3df target)
{
  if (_first)
    _target = target;
  _first = false;
  _core->cam->setPosition(target + _offset);
  _core->cam->setTarget(target);
}

void Camera::move(irr::core::vector3df add)
{
  //this->setPosSlow(this->getPos() + add);
  //_target = this->getPos();
  _target += (add * CAMERA_MOVE);
}

std::string Camera::getType() const
{
  return ("camera");
}
