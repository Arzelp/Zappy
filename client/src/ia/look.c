/*
** look.c for look in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 20 22:11:11 2017 Paskal Arzel
** Last update Sun Jul  2 20:29:08 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core.h"

static int	get_nb_obj(char *objects)
{
  int i;
  int	res;

  if (!strcmp("", objects))
    return (0);
  i = 0;
  res = 1;
  while (objects[i])
    {
      if (objects[i] == ' ')
	      res++;
      i++;
    }
  return (res);
}

static bool	is_needing(void)
{
  int	i;
  const t_elevation *need;

  i = 0;
  need = elevation_get_infos();
  if (g_core->player.inventory[FOOD] < MIN_SAFE_FOOD)
    return (true);
  while (i < FOOD)
    {
      if (g_core->player.inventory[i] < (int)need->object[i])
				return (true);
      i++;
    }
  return (false);
}

static bool	is_interesting(void)
{
  int i;
  int	nb_obj;

  i = 0;
  nb_obj = 0;
  if (g_core->player.level < 2)
    return (true);
  while (i < DELT_MAX_LVL * DELT_MAX_LVL)
    {
      nb_obj += get_nb_obj(g_core->player.view[i]);
      i++;
    }
  if (!is_needing())
    return (false);
  if (nb_obj >= g_core->player.level * 2)
    return (true);
  return (false);
}

bool	look(void)
{
  static int i;

  i++;
  if (!player_look(NULL))
    return (false);
  if (is_interesting())
      set_rush();
  if (manage_message() == false)
    	loot(g_core->player.view[0]);
  return (true);
}
