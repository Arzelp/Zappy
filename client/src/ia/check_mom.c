/*
** check_mom.c for check_mom.c in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 20 20:19:07 2017 Paskal Arzel
** Last update Tue Jun 20 22:16:52 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

static bool	check_fertility()
{
  if (g_core->player.inventory[FOOD] > 2 && !g_core->player.cd_fertility)
  {
    if (!player_connect_nbr(NULL))
			return (false);
    if (g_core->player.connect_nbr)
	    return (true);
  }
  return (false);
}

bool	check_mom(void)
{
  if (check_fertility())
  {
    if (!player_fork(NULL))
	    return (false);
    return (true);
  }
  return (false);
}
