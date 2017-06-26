//
// ZappyCmd.cpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon Jun 26 16:01:18 2017 arnaud.alies
// Last update Mon Jun 26 18:22:44 2017 arnaud.alies
//

#include "Zappy.hpp"
#include "Player.hpp"
#include "Random.hpp"
#include "Egg.hpp"

void Zappy::cmd_msz(int ac, std::vector<std::string> av)
{
  /* INIT */
  int width = 0;
  int height = 0;

  if (ac != 3)
    return ;
  if (_running == false)
    {
      width = Zappy::getInt(av.at(1));
      height = Zappy::getInt(av.at(2));
      if (width < 0)
        width = 3;
      if (height < 0)
        height = 3;
      _map = new Map(_core, width, height);
      _entity_manager = new EntityManager(_core, _map);
      _cam = _entity_manager->addEntityMap<Camera>(_map->getWidth() / 2, _map->getHeight() / 2);
      this->spawnResources();
      _running = true;
      _entity_manager->update();
      //
      _entity_manager->addEntityMap<Egg>(1, 1);
    }
}

void Zappy::cmd_bct(int ac, std::vector<std::string> av)
{
  int values[R_SIZE];
  int x;
  int y;

  if (ac != 10 || _running == false)
    return ;
  x = Zappy::getInt(av.at(1));
  y = Zappy::getInt(av.at(2));
  for (int i = 0; i < R_SIZE; i += 1)
    {
      values[i] = Zappy::getInt(av.at(i + 3));
    }
  Resources* res = this->getResourcesAt(Map::getAbs(x, y));
  if (res != nullptr)
    {
      res->setValues(values);
    }
}

void Zappy::cmd_pnw(int ac, std::vector<std::string> av)
{
  Player* player;
  int id, x, y, orientation, level;
  std::string team;

  if (ac != 7 || _running == false)
    return ;
  id = Zappy::getInt(av.at(1));
  x = Zappy::getInt(av.at(2));
  y = Zappy::getInt(av.at(3));
  orientation = Zappy::getInt(av.at(4));
  level = Zappy::getInt(av.at(5));
  team = av.at(6);
  if (this->getPlayerById(id) != nullptr)
    {
      std::cerr << "Player already exists" << std::endl;
      return ;
    }
  player = _entity_manager->addEntityMap<Player>(x, y);
  player->id = id;
  player->team = team;
  player->level = level;
}

void Zappy::cmd_ppo(int ac, std::vector<std::string> av)
{
  Player* player;
  int id, x, y, orientation, level;

  if (ac != 5 || _running == false)
    return ;
  id = Zappy::getInt(av.at(1));
  x = Zappy::getInt(av.at(2));
  y = Zappy::getInt(av.at(3));
  orientation = Zappy::getInt(av.at(4));
  if ((player = this->getPlayerById(id)) == nullptr)
    return ;
  if (orientation == 1)
    player->setRotation(irr::core::vector3df(0, 0, 0));
  else if (orientation == 2)
    player->setRotation(irr::core::vector3df(0, 90, 0));
  else if (orientation == 3)
    player->setRotation(irr::core::vector3df(0, 180, 0));
  else if (orientation == 4)
    player->setRotation(irr::core::vector3df(0, -90, 0));
  player->moveTo(x, y);
}

void Zappy::cmd_pdi(int ac, std::vector<std::string> av)
{
  Player* player;
  int id;
  
  if (ac != 2 || _running == false)
    return ;
  id = Zappy::getInt(av.at(1));
  if ((player = this->getPlayerById(id)) == nullptr)
    return ;
  player->kill();
}

