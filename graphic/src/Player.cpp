//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Thu Jun 29 15:46:02 2017 arnaud.alies
//

#include "Player.hpp"
#include "EntityManager.hpp"

Player::Player() :
  _offset(irr::core::vector3df(0, 50, 0)),
  _billboard_offset(irr::core::vector3df(0, 150, 0)),
  _alive(true),
  _first(true),
  _target(true)
{
  id = 0;
  _anim_time = 0;
}

void Player::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomberman/tris.md2",
                   irr::core::vector3df(2.5, 2.5, 2.5),
                   "./res/bomberman/Bomber.PCX",
		   true);
  _mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
  _hud_title = new HudText(core, "", 20);
}

Player::~Player()
{
  delete _mesh;
  delete _hud_title;
}

void Player::kill()
{
  if (_alive)
    _mesh->node->setMD2Animation(irr::scene::EMAT_BOOM);
  _alive = false;
  _death_time = Core::getTimeMs();
}

void Player::update()
{
  if (_alive == false)
    {
      if (_death_time < Core::getTimeMs() - 1000)
	_entity_manager->queueDeleteEntity(this);
      return ;
    }
  irr::core::vector3df pos = this->getPos();
  irr::core::vector3df diff = _target - pos;

  this->setPos((diff / PLAYER_SPEED) + pos);
  _hud_title->setPos(this->getPos() + _billboard_offset);
  _hud_title->setText(team + ":" + std::to_string(level));
  if (_anim_time != 0)
    {
      if (_anim_time < Core::getTimeMs())
	{
	  _mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
	  _anim_time = 0;
	}
    }
  /* animations */
  //_mesh->node->setMD2Animation(irr::scene::EMAT_RUN);
  //_mesh->node->setMD2Animation(irr::scene::EMAT_PAIN_A);
  //_mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
}

void Player::moveTo(int x, int y)
{
  _target = Map::getAbs(x, y);
}

void Player::animate(irr::scene::EMD2_ANIMATION_TYPE anim, int time)
{
  _mesh->node->setMD2Animation(anim);
  _anim_time = Core::getTimeMs() + time;
}

void Player::setPos(irr::core::vector3df target)
{
  if (_first)
    _target = target;
  _mesh->node->setPosition(target + _offset);
  _first = false;
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
