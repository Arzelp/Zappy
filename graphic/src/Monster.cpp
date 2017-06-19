//
// Player.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 15:13:35 2017 arnaud.alies
// Last update Fri Jun 16 10:39:46 2017 arnaud.alies
//

#include "Monster.hpp"
#include "EntityManager.hpp"
#include "Bomb.hpp"
#include "Random.hpp"

Monster::Monster()
{
  _id = Random::randint(5, 1000);
  _speed = ((float)Random::randint(20, 50)) / 10.0;
}

Monster::~Monster()
{
}

void Monster::init(Core* core, Map *map, EntityManager* entity_manager)
{
  APlayer::init(core, map, entity_manager);
  _mesh = new Mesh(_core,
                   "./res/bomberman/tris.md2",
                   irr::core::vector3df(4, 4, 4),
                   "./res/bomberman/QuakeII.pcx");
  _mesh->node->setMD2Animation(irr::scene::EMAT_STAND);
}

bool Monster::checkMove(int x, int y)
{
  int monster_x;
  int monster_y;

  this->getPosMap(&monster_x, &monster_y);
  EMap e = _map->get(monster_x + x, monster_y + y);
  if (e == M_EMPTY)
    return (true);
  return (false);
}

EState Monster::getState()
{
  EState res = S_IDLE;
  int monster_x, monster_y;
  int player_x, player_y;
  int diff_x, diff_y;
  APlayer *closestPlayer;

  closestPlayer = static_cast<APlayer*>(_entity_manager->getClosestEntity(this->getPos(),
									  "player",
									  this));
  if (closestPlayer != nullptr)
    {
      this->getPosMap(&monster_x, &monster_y);
      closestPlayer->getPosMap(&player_x, &player_y);
      diff_x = monster_x - player_x;
      diff_y = monster_y - player_y;
      
      if (diff_y < 0 && this->checkMove(0, 1))
	res = S_RUN_LEFT;
      else if (diff_y > 0 && this->checkMove(0, -1))
	res = S_RUN_RIGHT;
      if (diff_x < 0 && this->checkMove(1, 0))
	res = S_RUN_UP;
      else if (diff_x > 0 && this->checkMove(-1, 0))
	res = S_RUN_DOWN;
    }
  return (res);
}

void Monster::update()
{
  APlayer::update();

  if (this->isAlive())
    {
      std::vector<AEntity*> players = _entity_manager->getInRange(this->getPos(), UNIT * 1.5, "player");
      if (players.size() > 0)
	{
	  if (_sound_buffer.loadFromFile("./res/sounds/allahuakbar.ogg"))
	    {
	      _sound.setBuffer(_sound_buffer);
	      _sound.play();
	    }
	  Bomb* bomb = this->plantBomb();
	  if (bomb != nullptr)
	    bomb->timer = 0;
	}
    }
}

std::string Monster::getType() const
{
  return ("npc");
}
