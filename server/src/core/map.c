/*
** ressource_tab.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 18:16:48 2017 Arthur Josso
** Last update Sat Jun 17 20:47:08 2017 Arthur Josso
*/

#include <stdlib.h>
#include "core.h"

const char	*g_ressources[] =
  {
    " food",
    " linemate",
    " deraumere",
    " sibur",
    " mendiane",
    " phiras",
    " thystame",
    NULL
  };

static uint16_t	how_many_pop()
{
  uint16_t     	throw;

  throw = rand() % 100;
  if (throw > DROP_PROBABILITY)
    return (0);
  else if (throw > DROP_PROBABILITY / 4)
    return (1);
  else
    return (2);
}

void		init_map()
{
  t_pos		pos;
  t_ressource	res;

  g_game->map = cleaner_malloc(sizeof(uint16_t*) * g_game->map_size.y);
  pos.y = 0;
  while (pos.y < g_game->map_size.y)
    {
      g_game->map[pos.y] = cleaner_malloc(sizeof(uint16_t*) *
					  g_game->map_size.x);
      pos.x = 0;
      while (pos.x < g_game->map_size.x)
	{
	  g_game->map[pos.y][pos.x] = cleaner_malloc(sizeof(uint16_t) *
						     RES_NBR);
	  res = RES_FOOD;
	  while (res != RES_NBR)
	    {
	      g_game->map[pos.y][pos.x][res] = how_many_pop();
	      res++;
	    }
	  pos.x++;
	}
      pos.y++;
    }
}
