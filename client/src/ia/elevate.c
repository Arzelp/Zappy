/*
** elevate.c for elevate in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 27 18:32:41 2017 Paskal Arzel
** Last update Tue Jun 27 20:17:25 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

void	elevate(void)
{
  int	i;
  const t_elevation *need;

  i = 0;
  need = elevation_get_infos();
  player_inventory(NULL);
  printf("try elevate\n");
  while (i < FOOD)
  {
    if ((unsigned int)g_core->player.inventory[i] < need->object[i])
	    return;
    i++;
  }
  printf("going to elevate\n");
  player_incantation(NULL);
  player_inventory(NULL);
}
