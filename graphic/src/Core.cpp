//
// Core.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 12:36:35 2017 arnaud.alies
// Last update Wed Jun 14 15:35:52 2017 arnaud.alies
//

#include <chrono>
#include <ctime>
#include <iostream>
#include "Core.hpp"
#include "Welcome.hpp"

int Core::getTime()
{
  return (static_cast<long int>(std::time(nullptr)));
}

int Core::getTimeMs()
{
  std::chrono::milliseconds ms =
    std::chrono::duration_cast<std::chrono::milliseconds>
    (std::chrono::system_clock::now().time_since_epoch());
  return (ms.count());
}

void Core::stop()
{
  _running = false;
}

Core::Core()
{
  _running = true;
  receiver = new MyEventReceiver();
  device = irr::createDevice(irr::video::EDT_OPENGL,
			     irr::core::dimension2d<irr::u32>(WIDTH, HEIGHT), 16,
			     false, false, true, receiver);
  //!device
  device->setWindowCaption(L"ISIS rp");
  video = device->getVideoDriver();
  scene = device->getSceneManager();
  gui = device->getGUIEnvironment();
  //gui font
  irr::gui::IGUISkin* skin = gui->getSkin();
  irr::gui::IGUIFont* font = gui->getFont("./res/font.bmp");
  if (font)
    skin->setFont(font);
  else
    std::cerr << "error while loading font" << std::endl;
  //
  cam = scene->addCameraSceneNode();
  state = new Welcome();
  state->begin(this);
}

Core::~Core()
{
  delete state;
  device->drop();
}

void Core::run()
{
  State *buff;
  sf::SoundBuffer click_buffer;
  if (!click_buffer.loadFromFile("./res/sounds/click.ogg"))
    return ;
  sf::Sound click;
  click.setBuffer(click_buffer);

  if (sound_buffer.loadFromFile("./res/sounds/yallah.ogg"))
    {
      sound.setBuffer(sound_buffer);
      sound.setLoop(true);
      if (settings.get().music)
	sound.play();
    }

  while (device->run() && _running)
    {
      video->beginScene(true, true, irr::video::SColor(255, 100, 101, 255));
      gui->drawAll();
      scene->drawAll();
      buff = state->update();
      video->endScene();
      if (buff != nullptr)
	{
	  delete state;
	  buff->begin(this);
	  state = buff;
	  click.play();
	}
    }
}
