//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Mon Jun 19 18:14:29 2017 arnaud.alies
//

#include "APlayer.hpp"
#include "EntityManager.hpp"

APlayer::APlayer() :
  _offset(irr::core::vector3df(0, 50, 0)),
  _state(S_IDLE),
  _speed(10),
  _alive(true),
  _id(0)
{
}

void APlayer::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
}

APlayer::~APlayer()
{
  delete _mesh;
}

void APlayer::kill()
{
  if (_alive)
    _mesh->node->setMD2Animation(irr::scene::EMAT_BOOM);
  _alive = false;
}

void APlayer::validMove(irr::core::vector3df dir)
{
  this->setPos(_map->getValidPos(this->getPos(), dir));
}

void APlayer::update()
{
  if (_alive == false)
    return ;
  EState old_state = _state;

  _state = this->getState();
  /* actions */
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
  else if (_state == S_PLANT)
    {
    }
  /* animations */
  if (old_state != _state)
    {
      if (_state == S_RUN_UP
	  || _state == S_RUN_DOWN
	  || _state == S_RUN_RIGHT
	  || _state == S_RUN_LEFT)
	_mesh->node->setMD2Animation(irr::scene::EMAT_RUN);
      if (_state == S_PLANT)
	_mesh->node->setMD2Animation(irr::scene::EMAT_PAIN_A);
      if (_state == S_IDLE)
	_mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
    }
  //_mesh->node->setRotation(rot + irr::core::vector3df(0, rot_speed, 0));
  //pf("IN RANGE: %d\n", _entity_manager->getInRange(this->getPos(), UNIT).size());
}

void APlayer::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target + _offset);
}

irr::core::vector3df APlayer::getPos() const
{
  return (_mesh->node->getPosition() - _offset);
}

irr::core::vector3df APlayer::getRotation() const
{
  return (_mesh->node->getRotation());
}

void APlayer::setRotation(irr::core::vector3df rot)
{
  _mesh->node->setRotation(rot);
}

std::string APlayer::getType() const
{
  return ("player");
}

bool APlayer::isAlive() const
{
  return (_alive);
}
