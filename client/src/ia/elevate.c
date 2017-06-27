/*
** elevate.c for elevate in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 27 18:32:41 2017 Paskal Arzel
** Last update Tue Jun 27 20:23:06 2017 Paskal Arzel
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
  printf("needing : \n");
  printf("food : %d/0\n", g_core->player.inventory[FOOD]);
  while (i < FOOD)
  {
    printf("%s : %d/%d\n", g_elem[i].name, g_core->player.inventory[i], need->object[i]);
    if ((unsigned int)g_core->player.inventory[i] < need->object[i])
	    return;
    i++;
  }
  printf("going to elevate\n");
  player_incantation(NULL);
  player_inventory(NULL);
}
