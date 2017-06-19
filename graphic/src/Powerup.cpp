//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Fri Jun 16 10:40:52 2017 arnaud.alies
//

#include "Random.hpp"
#include "Map.hpp"
#include "Powerup.hpp"
#include "EntityManager.hpp"
#include "APlayer.hpp"

Powerup::Powerup()
{
  int rand = Random::randint(0, 100);
  if (rand < 20)
    _power = P_SPEED;
  else if (rand < 70)
    _power = P_ADD_BOMB;
  else
    _power = P_RANGE;
}

void Powerup::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);

  if (_power == P_SPEED)
    {
      _mesh = new Mesh(_core,
		       "./res/coin/dogecoin.obj",
		       irr::core::vector3df(0.4, 0.4, 0.4),
		       "./res/coin/speed.jpg");
      _mesh->node->setRotation(irr::core::vector3df(180,0,100));
    }
  else if (_power == P_RANGE)
    {
      _mesh = new Mesh(_core,
		       "./res/coin/dogecoin.obj",
		       irr::core::vector3df(0.4, 0.4, 0.4),
		       "./res/coin/power.png");
      _mesh->node->setRotation(irr::core::vector3df(180,0,100));
    }
  else if (_power == P_ADD_BOMB)
    {
      _mesh = new Mesh(_core,
		       "./res/coin/dogecoin.obj",
		       irr::core::vector3df(0.4, 0.4, 0.4),
		       "./res/coin/bomb.png");
      _mesh->node->setRotation(irr::core::vector3df(180,0,100));
    }
  else
    _mesh = new Mesh(_core,
		     "./res/bomb/Bomb.obj",
		     irr::core::vector3df(220, 220, 220),
		     "./res/bomb/Albedo.png");
}

Powerup::~Powerup()
{
  delete _mesh;
}

void Powerup::update()
{
  irr::core::vector3df rot = _mesh->node->getRotation();;

  _mesh->node->setRotation(rot + irr::core::vector3df(0, 5, 0));

  std::vector<AEntity*> players = _entity_manager->getInRange(this->getPos(), UNIT / 2, "player");
  for (auto ent : players)
    {
      APlayer* player = static_cast<APlayer*>(ent);
      player->applyPowerup(_power);
    }
  if (players.size() > 0)
    this->kill();
}

void Powerup::setPos(irr::core::vector3df target)
{
  _mesh->node->setPosition(target + irr::core::vector3df(0,50,0));
}

irr::core::vector3df Powerup::getPos() const
{
  return (_mesh->node->getPosition() - irr::core::vector3df(0,50,0));
}

std::string Powerup::getType() const
{
  return ("powerup");
}
