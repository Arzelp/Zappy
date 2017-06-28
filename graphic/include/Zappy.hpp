//
// Welcome.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 10:45:13 2017 arnaud.alies
// Last update Wed Jun 28 15:57:32 2017 arnaud.alies
//

#ifndef ZAPPY_HPP_
#define ZAPPY_HPP_

#include <vector>
#include "Indie.h"
#include "Core.hpp"
#include "Map.hpp"
#include "State.hpp"
#include "EntityManager.hpp"
#include "AEntity.hpp"
#include "Image.hpp"
#include "Camera.hpp"
#include "Resources.hpp"
#include "Network.hpp"
#include "Player.hpp"

#define DEF_CMD(cmd) {#cmd, &Zappy::cmd_##cmd}

class Zappy : public State
{
protected:
  HudText* _inventory;
  Player* _selected;
  bool _running;
  Network* _network;
  Camera* _cam;
  Core* _core;
  EntityManager* _entity_manager;
  Map* _map;
  //
  Image* _img;
public:
  Zappy();
  virtual ~Zappy();
  State* update();
  void begin(Core*);
  void spawnResources();
  Resources* getResourcesAt(irr::core::vector3df pos);
  Player* getPlayerById(int id);
  //
  static int getInt(std::string);
  void runQueue();
  void cmd_msz(int ac, std::vector<std::string> av);
  void cmd_bct(int ac, std::vector<std::string> av);
  void cmd_pnw(int ac, std::vector<std::string> av);
  void cmd_ppo(int ac, std::vector<std::string> av);
  void cmd_pdi(int ac, std::vector<std::string> av);
  void cmd_pex(int ac, std::vector<std::string> av);
  void cmd_plv(int ac, std::vector<std::string> av);
  void cmd_pfk(int ac, std::vector<std::string> av);
  void cmd_pin(int ac, std::vector<std::string> av);
  void cmd_pgt(int ac, std::vector<std::string> av);
  void cmd_pdr(int ac, std::vector<std::string> av);
};

typedef void(Zappy::*t_command)(int ac, std::vector<std::string> av);

#endif
