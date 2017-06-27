//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Tue Jun 27 10:57:14 2017 arnaud.alies
//

#include "Player.hpp"
#include "EntityManager.hpp"

Player::Player() :
  _offset(irr::core::vector3df(0, 50, 0)),
  _billboard_offset(irr::core::vector3df(0, 150, 0)),
  _alive(true)
{
  id = 0;
}

void Player::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomberman/tris.md2",
                   irr::core::vector3df(3, 3, 3),
                   "./res/bomberman/Bomber.PCX");
  _mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
  _billboard = _core->scene->addBillboardTextSceneNode(_core->font,
						       irr::core::stringw("").c_str(),
						       0,
						       irr::core::dimension2d<irr::f32>(140.0f, 50.0f));
}

Player::~Player()
{
  delete _mesh;
  _billboard->remove();
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
  _billboard->setPosition(this->getPos() + _billboard_offset);
  _billboard->setText(irr::core::stringw((team
					  + ":"
					  + std::to_string(level)).c_str()).c_str());
  /* animations */
  //_mesh->node->setMD2Animation(irr::scene::EMAT_RUN);
  //_mesh->node->setMD2Animation(irr::scene::EMAT_PAIN_A);
  //_mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
}

void Player::moveTo(int x, int y)
{
  _target = Map::getAbs(x, y);
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
