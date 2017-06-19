//
// Bomb.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Wed Jun  7 17:29:46 2017 arnaud.alies
//

#ifndef GATE_HPP_
#define GATE_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

class Gate : public AEntity
{
protected:
  Mesh* _mesh;
public:
  Gate();
  virtual ~Gate();
  void init(Core*, Map*, EntityManager*);
  void update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType() const;
};

#endif
