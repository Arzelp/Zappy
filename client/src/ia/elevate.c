/*
** elevate.c for elevate in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 27 18:32:41 2017 Paskal Arzel
** Last update Sun Jul  2 20:33:21 2017 Paskal Arzel
*/

#include <math.h>
#include <stdlib.h>
#include "core.h"

static void	drop_elevation(const t_elevation *need)
{
  int casevalue;
  int	todrop;
  int i;

  i = 0;
  casevalue = calc_value(g_core->player.view[0]);
  while (i < FOOD)
	{
    todrop = (int)(need->object[i] -
      (casevalue % (int)pow(10, i + 1)) / pow(10, i));
    while (todrop > 0)
    {
      if (!player_set(g_elem[i].name))
	      return;
      todrop--;
    }
    i++;
  }
}

void	elevate(void)
{
  int	i;
  const t_elevation *need;

  i = 0;
  need = elevation_get_infos();
  player_inventory(NULL);
  while (i < FOOD)
  {
    if ((unsigned int)g_core->player.inventory[i] < need->object[i])
	    return;
    i++;
  }
  if (!player_look(NULL))
    return;
  if (count_player(g_core->player.view[0]) < need->nb_player)
    return;
  drop_elevation(need);
  player_incantation(NULL);
  player_inventory(NULL);
}
