//
// Camera.hpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun 20 13:57:05 2017 arnaud.alies
// Last update Thu Jun 22 09:58:26 2017 arnaud.alies
//

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#define CAMERA_OFFSET (1000)

//lower = faster
#define CAMERA_SPEED (50)

#define CAMERA_MOVE (15)

#include "AEntity.hpp"

class Camera : public AEntity
{
protected:
  irr::core::vector3df _offset;
  irr::core::vector3df _target;
  bool _first;
public:
  Camera();
  virtual ~Camera();
  void init(Core*, Map*, EntityManager*);
  std::string getType() const;
  void update();
  irr::core::vector3df getPos() const;
  void setPos(irr::core::vector3df target);
  //custom
  void setPosSlow(irr::core::vector3df target);
  void move(irr::core::vector3df add);
};

#endif
