//
// Egg.hpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Mon Jun 26 14:09:38 2017 arnaud.alies
// Last update Mon Jun 26 15:03:07 2017 arnaud.alies
//

#ifndef EGG_HPP_
#define EGG_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

class Egg : public AEntity
{
protected:
  Mesh* _mesh;
  irr::core::vector3df _offset;
public:
  std::string team;
  int id;
public:
  Egg();
  virtual ~Egg();
  void init(Core* core, Map* map, EntityManager* entity_manager);
  void update();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType();
  void kill();
};

#endif
