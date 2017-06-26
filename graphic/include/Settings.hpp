//
// Settings.hpp for hue in /home/arnaud.alies/rendu/cpp_indie_studio
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Tue Jun 13 13:53:47 2017 arnaud.alies
// Last update Mon Jun 26 13:45:12 2017 arnaud.alies
//

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

struct Data
{
  bool music;
};

class Settings
{
protected:
  Data _data;
  void load();
  void save();
public:
  Settings();
  virtual ~Settings();
  Data& get();
};

#endif
