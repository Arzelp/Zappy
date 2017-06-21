//
// Camera.hpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun 20 13:57:05 2017 arnaud.alies
// Last update Wed Jun 21 14:06:23 2017 arnaud.alies
//

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#define CAMERA_OFFSET (1000)

#include "AEntity.hpp"

class Camera : public AEntity
{
protected:
  irr::core::vector3df _offset;
public:
  Camera();
  virtual ~Camera();
  void init(Core*, Map*, EntityManager*);
  std::string getType() const;
  void update();
  irr::core::vector3df getPos() const;
  void setPos(irr::core::vector3df target);
};

#endif
