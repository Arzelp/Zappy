//
// Resources.hpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu Jun 22 17:01:44 2017 arnaud.alies
// Last update Tue Jun 27 16:22:16 2017 arnaud.alies
//

#ifndef RESOURCES_HPP_
#define RESOURCES_HPP_

#include "Mesh.hpp"
#include "AEntity.hpp"

#define R_SIZE (7)
#define R_EFFECT_SPEED (10.0)

class Resources : public AEntity
{
protected:
  float _scale;
  irr::core::vector3df _offset;
  irr::core::vector3df _pos;
  float _values[R_SIZE];
  bool _updated;
protected:
  Mesh* _meshes[R_SIZE];
public:
  Resources();
  virtual ~Resources();
  virtual void init(Core*, Map*, EntityManager*);
  void update();
  irr::core::vector3df getPos() const;
  void setPos(irr::core::vector3df target);
  void setValues(int* values);
  std::string getType() const;
};

#endif
