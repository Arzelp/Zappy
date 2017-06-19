//
// Bomber.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Sun May 28 17:29:25 2017 arnaud.alies
// Last update Fri Jun 16 11:08:52 2017 arnaud.alies
//

#include "Explosion.hpp"
#include "EntityManager.hpp"

Explosion::Explosion()
{
  _time = Core::getTimeMs();
  _first = true;
}

void Explosion::init(Core* core, Map *map, EntityManager* entity_manager)
{
  AEntity::init(core, map, entity_manager);

  
  /* particle init */
  _particle = _core->scene->addParticleSystemSceneNode();

  _particle->setPosition(this->getPos());
  _particle->setScale(irr::core::vector3df(4,4,4));
  _particle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _particle->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
  _particle->setMaterialTexture(0, _core->video->getTexture("./res/fire.bmp"));
  _particle->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
  irr::scene::IParticleEmitter* emitter =
    _particle->createBoxEmitter(irr::core::aabbox3d<irr::f32>(-8,0,-8,8,8,8),
				irr::core::vector3df(0.0f,0.05f,0.0f),
				20,5,
				irr::video::SColor(0,255,255,255),
				irr::video::SColor(0,255,255,255), 1100,2000);
  emitter->setMinStartSize(irr::core::dimension2df(10.0f, 10.0f));
  emitter->setMaxStartSize(irr::core::dimension2df(50.0f, 50.0f));
  
  _particle->setEmitter(emitter);
  emitter->drop();
  irr::scene::IParticleAffector* paf = _particle->createFadeOutParticleAffector();
  _particle->addAffector(paf);
  paf->drop();
}

Explosion::~Explosion()
{
  _particle->remove();
}

void Explosion::bombEntity(std::string type)
{
  std::vector<AEntity*> ents = _entity_manager->getInRange(this->getPos(), UNIT / 2, type);
  for (auto ent : ents)
    {
      //_entity_manager->queueDeleteEntity(ent);
      ent->kill();
    }
}


void Explosion::play()
{
  if (_sound_buffer.loadFromFile("./res/sounds/explosion.ogg"))
    {
      _sound.setBuffer(_sound_buffer);
      _sound.play();
    }
}

void Explosion::update()
{
  /* destroy nearby entities */
  if (_first)
    {
      this->bombEntity("player:bomb:box:npc");
      _first = false;
    }
  /* set map collision */
  int x, y;
  this->getPosMap(&x, &y);
  //_entity_manager->getInRange(this->getPos(), UNIT, "player")
  
  int ctime = Core::getTimeMs();
  if (_time + EXPLOSION_TIMER < ctime)
    _entity_manager->queueDeleteEntity(this);
}

void Explosion::setPos(irr::core::vector3df target)
{
  _particle->setPosition(target + irr::core::vector3df(0,50,0));
}

irr::core::vector3df Explosion::getPos() const
{
  return (_particle->getPosition() - irr::core::vector3df(0,50,0));
}

std::string Explosion::getType() const
{
  return ("explosion");
}
