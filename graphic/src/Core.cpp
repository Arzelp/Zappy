//
// Core.cpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Thu May  4 12:36:35 2017 arnaud.alies
// Last update Fri Jun 30 18:47:18 2017 arnaud.alies
//

#include <chrono>
#include <ctime>
#include <iostream>
#include "Core.hpp"
#include "MainMenu.hpp"

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
  device->setWindowCaption(L"bork");
  video = device->getVideoDriver();
  scene = device->getSceneManager();
  gui = device->getGUIEnvironment();
  //gui font
  irr::gui::IGUISkin* skin = gui->getSkin();
  font = gui->getFont("./res/font.bmp");
  if (font)
    skin->setFont(font);
  else
    std::cerr << "error while loading font" << std::endl;
  //
  cam = scene->addCameraSceneNode();
  state = new MainMenu();
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

  if (sound_buffer.loadFromFile("./res/sounds/bork.ogg"))
    {
      sound.setBuffer(sound_buffer);
      sound.setLoop(true);
      if (settings.get().music)
	sound.play();
    }

  while (device->run() && _running)
    {
      video->beginScene(true, true, irr::video::SColor(255, 217, 189, 98));
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

irr::core::rect<irr::s32> Core::getDim(float margin, int pos, int height)
{
  irr::core::rect<irr::s32> res;

  res = irr::core::rect<irr::s32>(WIDTH * margin, pos,
                                  WIDTH * (1.0 - margin), pos + height);
  return (res);
}

irr::scene::ISceneNode* Core::getNodeFromMouse()
{
  irr::scene::ISceneCollisionManager* scm = this->scene->getSceneCollisionManager();
  irr::core::line3d<irr::f32> ray =
    scm->getRayFromScreenCoordinates(this->device->getCursorControl()->getPosition(),
				     this->cam);
  irr::core::triangle3df tri;
  irr::core::vector3df col;
  irr::scene::ISceneNode* node = scm->getSceneNodeAndCollisionPointFromRay(ray, col, tri);
  return (node);
}

irr::core::position2d<irr::s32> Core::getViewPos(irr::core::vector3df pos)
{
  irr::f32 transpos[4];
  irr::core::matrix4 trans;
  irr::core::position2d<irr::s32> pos2d;
  irr::core::dimension2d<irr::u32> dim = this->video->getScreenSize();
  dim.Width /= 2;
  dim.Height /= 2;
  trans *= this->scene->getActiveCamera()->getProjectionMatrix();
  trans *= this->scene->getActiveCamera()->getViewMatrix();
  transpos[0] = pos.X;
  transpos[1] = pos.Y;
  transpos[2] = pos.Z;
  transpos[3] = 1.0f;
  trans.multiplyWith1x4Matrix(transpos);
  irr::f32 zDiv = transpos[3] == (0.0f ? 1.0f : (1.0f / transpos[3]));
  pos2d.X = (irr::s32)(dim.Width * transpos[0] * zDiv) + dim.Width;
  pos2d.Y = ((irr::s32)(dim.Height - (dim.Height * (transpos[1] * zDiv))));
  return (pos2d);
}
