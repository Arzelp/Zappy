//
// Box.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Sun Jun  4 14:31:45 2017 arnaud.alies
//

#ifndef BOX_HPP_
#define BOX_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

class Box : public AEntity
{  
protected:
  Mesh* _mesh;
public:
  Box();
  virtual ~Box();
  void init(Core*, Map*, EntityManager*);
  void update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType() const;
  virtual void kill();
};

#endif
