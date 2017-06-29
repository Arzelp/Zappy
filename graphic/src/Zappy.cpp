//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Thu Jun 29 16:55:38 2017 arnaud.alies
//

#include <map>
#include <sstream>
#include <vector>
#include <iostream>
#include "MainMenu.hpp"
#include "ErrorMenu.hpp"
#include "Zappy.hpp"
#include "Box.hpp"
#include "Random.hpp"
#include "Egg.hpp"

Zappy::Zappy() :
  _core(nullptr),
  _entity_manager(nullptr),
  _map(nullptr),
  _img(nullptr),
  _network(nullptr),
  _inventory(nullptr),
  _selected(nullptr),
  _running(false)
{
}

void Zappy::begin(Core* core)
{
  _core = core;
  try
    {
      _network = new Network("localhost", 4242);
      _network->ReceiveStart();
      _network->SendMsg("GRAPHIC");
      //_network->SendMsg("mct");
    }
  catch (const std::runtime_error& ex)
    {
      _network = nullptr;
    }
}

Zappy::~Zappy()
{
  delete _network;
  delete _entity_manager;
  delete _map;
  delete _inventory;
}

State *Zappy::update()
{
  E_INPUT in = _core->receiver->lastKey();

  if (in == K_ESCAPE || _network == nullptr)
    return (new ErrorMenu("CONNECTION ERROR"));
  this->runQueue();
  if (_running)
    {
      if (in == K_MOUSE_LEFT)
	{
	  irr::scene::ISceneNode* node = _core->getNodeFromMouse();
	  if (node != nullptr)
	    {
	      _selected =
		static_cast<Player*>(_entity_manager->getClosestEntity(node->getPosition(), "player"));
	      if (_selected != nullptr)
		_network->SendMsg("pin #" + std::to_string(_selected->id));
	    }
	  else
	    {
	      delete _inventory;
	      _inventory = nullptr;
	      _selected = nullptr;
	    }
	}
      if (_inventory != nullptr && _entity_manager->exists(_selected))
	{
	  _cam->setPosSlow(_selected->getPos());
	  _inventory->setPos(_selected->getPos() + irr::core::vector3df(20, 100, 0));
	}
      else
	{
	  delete _inventory;
	  _inventory = nullptr;
	}
        // Camera moves
      if (_core->receiver->keyState(K_UP))
	_cam->move(irr::core::vector3df(-1, 0, 0));
      if (_core->receiver->keyState(K_DOWN))
	_cam->move(irr::core::vector3df(1, 0, 0));
      if (_core->receiver->keyState(K_LEFT))
	_cam->move(irr::core::vector3df(0, 0, -1));
      if (_core->receiver->keyState(K_RIGHT))
	_cam->move(irr::core::vector3df(0, 0, 1));
      if (_core->receiver->keyState(K_Z))
	_cam->move(irr::core::vector3df(0, -1, 0));
      if (_core->receiver->keyState(K_S))
	_cam->move(irr::core::vector3df(0, 1, 0));
      if (_core->receiver->keyState(K_UP)
	  || _core->receiver->keyState(K_DOWN)
	  || _core->receiver->keyState(K_LEFT)
	  || _core->receiver->keyState(K_RIGHT)
	  || _core->receiver->keyState(K_Z)
	  || _core->receiver->keyState(K_S))
	{
	  delete _inventory;
          _inventory = nullptr;
	}
      _entity_manager->update();
    }
  return (nullptr);
}

Player* Zappy::getPlayerById(int id)
{
  Player* player;
  std::vector<AEntity*> ents = _entity_manager->getAll("player");

  for (auto ent : ents)
    {
      player = static_cast<Player*>(ent);
      if (player->id == id)
	return (player);
    }
  return (nullptr);
}

Egg* Zappy::getEggById(int id)
{
  Egg* egg;
  std::vector<AEntity*> ents = _entity_manager->getAll("egg");

  for (auto ent : ents)
    {
      egg = static_cast<Egg*>(ent);
      if (egg->id == id)
	return (egg);
    }
  return (nullptr);
}

Resources* Zappy::getResourcesAt(irr::core::vector3df pos)
{
  AEntity* ent;

  ent = _entity_manager->getClosestEntity(pos, "resources");
  return (static_cast<Resources*>(ent));
}

void Zappy::spawnResources()
{
  for (int y = 0; y < _map->getHeight(); y += 1)
    for (int x = 0; x < _map->getWidth(); x += 1)
      {
	_entity_manager->addEntityMap<Resources>(x, y);
      }
}

void Zappy::runQueue()
{
  std::map<std::string, t_command> command_map = {
    DEF_CMD(msz),
    DEF_CMD(pnw),
    DEF_CMD(ppo),
    DEF_CMD(pdi),
    DEF_CMD(pex),
    DEF_CMD(plv),
    DEF_CMD(pfk),
    DEF_CMD(pin),
    DEF_CMD(pgt),
    DEF_CMD(pdr),
    DEF_CMD(ebo),
    DEF_CMD(enw),
    DEF_CMD(pie),
    DEF_CMD(pic),
    DEF_CMD(pbc),
    DEF_CMD(bct)
  };

  std::string str;
  while ((str = _network->GetQueue()).size())
    {
      std::cout << str << "$" << std::endl;
      std::istringstream split(str);
      char delim = ' ';
      std::vector<std::string> tokens;
      t_command cmd;
      for (std::string each;
           std::getline(split, each, delim);
           tokens.push_back(each));
      cmd = command_map[tokens.at(0)];
      if (cmd != nullptr)
	(this->*(cmd))(tokens.size(), tokens);
    }
}

int Zappy::getInt(std::string str)
{
  if (str.size() <= 0)
    return (0);
  if (str[0] == '#')
    str[0] = '0';
  return (std::stoi("0" + str));
}
