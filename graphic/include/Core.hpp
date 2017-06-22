//
// Core.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 12:29:18 2017 arnaud.alies
// Last update Thu Jun 22 10:12:19 2017 arnaud.alies
//

#ifndef CORE_HPP_
#define CORE_HPP_

#include <ICameraSceneNode.h>
#include "Indie.h"
#include "State.hpp"
#include "MyEventReceiver.hpp"
#include "Settings.hpp"

#define SETTINGS (_core->settings.get())

class Core
{
protected:
  State* state;
  bool _running;
public:
  sf::SoundBuffer sound_buffer;
  sf::Sound sound;
public:
  MyEventReceiver* receiver;
  irr::IrrlichtDevice* device;
  irr::video::IVideoDriver* video;
  irr::scene::ISceneManager* scene;
  irr::gui::IGUIEnvironment* gui;
  irr::scene::ICameraSceneNode* cam;
  Settings settings;
public:
  Core();
  virtual ~Core();
  void run();
  void stop();
  static int getTime();
  static int getTimeMs();
  static irr::core::rect<irr::s32> getDim(float margin, int pos, int height = 50);
};

#endif
