/*
** look.c for look in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 20 22:11:11 2017 Paskal Arzel
** Last update Wed Jun 21 16:00:15 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "core.h"

static bool	can_teamplay(void)
{
  return (false);
}

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

static bool	is_interesting(void)
{
  int i;
  int	nb_obj;

  i = 0;
  nb_obj = 0;
  while (i < DELT_MAX_LVL * DELT_MAX_LVL)
    {
      nb_obj += get_nb_obj(g_core->player.view[i]);
      i++;
    }
  if (nb_obj >= g_core->player.level * 2)
    return (true);
  return (false);
}

bool	look(void)
{
  if (!player_look(NULL))
    return (false);
  if (can_teamplay())
    {
      printf("I'll try a strat\n");
    }
  if (is_interesting())
    {
      return (true);
    }
  return (true);
}
