//
// Team.hpp for hue in /home/arnaud.alies/rendu/PSU_2016_zappy/graphic
// 
// Made by arnaud.alies
// Login   <arnaud.alies@epitech.eu>
// 
// Started on  Wed Jun 28 16:39:55 2017 arnaud.alies
// Last update Wed Jun 28 16:42:39 2017 arnaud.alies
//

#ifndef TEAM_HPP_
#define TEAM_HPP_

#include "Indie.h"

class Team
{
protected:
  std::vector<std::string> _teams;
public:
  Team();
  virtual ~Team();
  void addTeam(std::string team);
  std::string getTexture(std::string team) const;
};

#endif
