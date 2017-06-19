//
// Powerup.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Mon Jun  5 20:59:07 2017 arnaud.alies
//

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

enum EPowerup
  {
    P_UNK = 0,
    P_RANGE,
    P_ADD_BOMB,
    P_SPEED
  };

class Powerup : public AEntity
{
protected:
  Mesh* _mesh;
  EPowerup _power;
public:
  Powerup();
  virtual ~Powerup();
  void init(Core*, Map*, EntityManager*);
  void update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType() const;
  //EPowerup getPower() const;
};

#endif
