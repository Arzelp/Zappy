//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Sun Jun 25 14:55:20 2017 arnaud.alies
//

#include "Player.hpp"
#include "EntityManager.hpp"

Player::Player() :
  _offset(irr::core::vector3df(0, 50, 0)),
  _alive(true)
{
  id = 0;
}

void Player::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
}

Player::~Player()
{
  delete _mesh;
}

void Player::kill()
{
  if (_alive)
    _mesh->node->setMD2Animation(irr::scene::EMAT_BOOM);
  _alive = false;
}

void Player::update()
{
  if (_alive == false)
    return ;

  /* actions */
  /*
  if (_state == S_RUN_UP)
    {
      this->validMove(irr::core::vector3df(_speed, 0, 0));
      this->setRotation(irr::core::vector3df(0, 0, 0));
    }
  else if (_state == S_RUN_DOWN)
    {
      this->validMove(irr::core::vector3df(-_speed, 0, 0));
      this->setRotation(irr::core::vector3df(0, 180, 0));
    }
  else if (_state == S_RUN_LEFT)
    {
      this->validMove(irr::core::vector3df(0, 0, _speed));
      this->setRotation(irr::core::vector3df(0, -90, 0));
    }
  else if (_state == S_RUN_RIGHT)
    {
      this->validMove(irr::core::vector3df(0, 0, -_speed));
      this->setRotation(irr::core::vector3df(0, 90, 0));
    }
  */
  /* animations */
  //_mesh->node->setMD2Animation(irr::scene::EMAT_RUN);
  //_mesh->node->setMD2Animation(irr::scene::EMAT_PAIN_A);
  //_mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
}

void Player::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target + _offset);
}

irr::core::vector3df Player::getPos() const
{
  return (_mesh->node->getPosition() - _offset);
}

irr::core::vector3df Player::getRotation() const
{
  return (_mesh->node->getRotation());
}

void Player::setRotation(irr::core::vector3df rot)
{
  _mesh->node->setRotation(rot);
}

std::string Player::getType() const
{
  return ("player");
}

bool Player::isAlive() const
{
  return (_alive);
}
