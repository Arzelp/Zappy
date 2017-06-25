//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Sun Jun 25 20:19:05 2017 arnaud.alies
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include "AEntity.hpp"
#include "Mesh.hpp"

class Player : public AEntity
{
protected:
  Mesh* _mesh;
  irr::core::vector3df _heading;
  irr::core::vector3df _offset;
  bool _alive;
public:
  int id;
  std::string team;
  int level;
public:
  Player();
  virtual ~Player();
  virtual void init(Core*, Map*, EntityManager*);
  void update();
  irr::core::vector3df getPos() const;
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getRotation() const;
  void setRotation(irr::core::vector3df rot);
  std::string getType() const;
  void kill();
  bool isAlive() const;
};

#endif
