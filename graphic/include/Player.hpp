//
// Player.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue May 30 14:56:43 2017 arnaud.alies
// Last update Tue Jun 27 18:20:12 2017 arnaud.alies
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include "AEntity.hpp"
#include "Mesh.hpp"
#include "HudText.hpp"

#define PLAYER_SPEED (50)

class Player : public AEntity
{
protected:
  Mesh* _mesh;
  /*
  irr::scene::IBillboardTextSceneNode *_billboard_text;
  irr::scene::IBillboardSceneNode *_billboard;
  */
  HudText* _hud_title;
  irr::core::vector3df _target;
  irr::core::vector3df _offset;
  irr::core::vector3df _billboard_offset;
  bool _alive;
  int _death_time;
  int _anim_time;
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
  void moveTo(int, int);
  void animate(irr::scene::EMD2_ANIMATION_TYPE anim, int time);
};

#endif
