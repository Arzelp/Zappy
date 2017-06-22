/*
** egg.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun 22 17:05:42 2017 Arthur Josso
** Last update Thu Jun 22 23:36:07 2017 Arthur Josso
*/

#pragma once

#include "types.h"

typedef struct s_egg t_egg;

struct s_egg
{
  uint32_t	id;
  uint32_t	layer_id;
  bool		is_hatched;
  t_time	hatching_time;
  t_pos		pos;
  t_team	*team;
  t_egg		*prev;
  t_egg		*next;
};

/*
** Init / Fini
*/

t_egg	*egg_add(t_player *layer);
void	egg_rm(t_egg *egg);

/*
** Tools
*/

typedef bool (*t_egg_func)(t_egg *egg);

void    egg_for_each(t_egg_func callback);

void    egg_check_hatch();
void	egg_can_use_one(t_player *player);
