//
// Welcome.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:46:49 2017 arnaud.alies
// Last update Sun Jun 25 10:55:40 2017 arnaud.alies
//

#include <sstream>
#include <vector>
#include <iostream>
#include "MainMenu.hpp"
#include "Zappy.hpp"
#include "Box.hpp"
#include "Random.hpp"

Zappy::Zappy() :
  _core(nullptr),
  _entity_manager(nullptr),
  _map(nullptr),
  _img(nullptr),
  _running(false)
{
}

Zappy::~Zappy()
{
  delete _entity_manager;
  delete _map;
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
  std::string str;
  if ((str = _network->GetQueue()).size())
    {
      std::cout << str << "$" << std::endl;
      std::istringstream split(str);
      char delim = ' ';
      std::vector<std::string> tokens;
      for (std::string each;
           std::getline(split, each, delim);
           tokens.push_back(each));
      if (tokens.at(0) == "msz")
        {
          this->run_msz(tokens.size(), tokens);
        }
      if (tokens.at(0) == "bct")
        {
          this->run_msz(tokens.size(), tokens);
        }
    }
}

State *Zappy::update()
{
  E_INPUT in = _core->receiver->lastKey();

  if (in == K_ESCAPE)
    return (new MainMenu());
  this->runQueue();
  /*
      if (!_network->SendMsg("name1"))
	{
	  _network->ReceiveStop();
	  return (1);
	}
    }
  */
  if (_running)
    {
      if (in == K_SPACE)
	{
	  irr::scene::ISceneNode* node = _core->getNodeFromMouse();
	  if (node != nullptr)
	    {
	      _cam->setPosSlow(node->getPosition());
	      Resources* res = this->getResourcesAt(node->getPosition());
	      if (res != nullptr)
		{
		  int values[] = {1, 2, 3, 4, 5, 6, 7};
		  res->setValues(values);
		}
	      /*
		irr::core::position2d<irr::s32> pos2d = _core->getViewPos(node->getPosition());
		delete _img;
		_img = new Image(_core,
		_core->video->getTexture((char*)"./res/one.png"),
		pos2d);
	      */
	    }
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
      _entity_manager->update();
    }
  else
    {
      // loading screen here
    }
  return (nullptr);
}

void Zappy::begin(Core* core)
{
  _core = core;
  
  _network = new Network("localhost", 4242);
  _network->ReceiveStart();
  _network->SendMsg("GRAPHIC");
  //_network->SendMsg("msz");
}

void Zappy::run_msz(int ac, std::vector<std::string> av)
{
  int width = 0;
  int height = 0;

  if (ac != 3)
    return ;
  if (_running == false)
    {
      width = std::stoi("0" + av.at(1));
      height = std::stoi("0" + av.at(2));
      if (width < 0)
	width = 3;
      if (height < 0)
	height = 3;
      _map = new Map(_core, width, height);
      _entity_manager = new EntityManager(_core, _map);
      _cam = _entity_manager->addEntityMap<Camera>(_map->getWidth() / 2, _map->getHeight() / 2);
      this->spawnResources();
      _running = true;
    }
}

void Zappy::run_bct(int ac, std::vector<std::string> av)
{
  int values[R_SIZE];
  int x;
  int y;

  if (ac != 10)
    return ;
  x = std::stoi("0" + av.at(1));
  y = std::stoi("0" + av.at(2));
  for (int i = 0; i < R_SIZE; i += 1)
    {
      values[i] = std::stoi("0" + av.at(i + 3));
    }
  Resources* res = this->getResourcesAt(Map::getAbs(x, y));
  if (res != nullptr)
    {
      res->setValues(values);
    }
}
