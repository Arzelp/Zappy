//
// Bomb.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 16:09:08 2017 arnaud.alies
// Last update Fri Jun  9 11:16:42 2017 arnaud.alies
//

#ifndef EXPLOSION_HPP_
#define EXPLOSION_HPP_

#include "AEntity.hpp"
#include "Mesh.hpp"

#define EXPLOSION_TIMER (700)

class Explosion : public AEntity
{
protected:
  irr::scene::IParticleSystemSceneNode* _particle;
  //irr::scene::IParticleEmitter* _emitter;
  int _time;
private:
  void bombEntity(std::string type);
  bool _first;
  //sound
  sf::SoundBuffer _sound_buffer;
  sf::Sound _sound;
public:
  Explosion();
  virtual ~Explosion();
  void init(Core*, Map*, EntityManager*);
  void update();
  void play();
  void setPos(irr::core::vector3df target);
  irr::core::vector3df getPos() const;
  std::string getType() const;
};

#endif
