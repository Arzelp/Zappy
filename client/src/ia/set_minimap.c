/*
** set_minimap.c for minimp in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Jun 21 17:52:21 2017 Paskal Arzel
** Last update Sun Jul  2 20:35:56 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <string.h>
#include "core.h"

static void	complete_minimap(int **minimap)
{
  int		i;
  int		j;
  int		k;
  int		max;

  i = 0;
  k = (g_core->player.level + 1) * (g_core->player.level + 1) - 1;
  max = g_core->player.level * 2 + 1;
  while (i <= g_core->player.level)
  {
    j = i;
    while (j < max && k >= 0)
    {
	    minimap[i][j] = calc_value(g_core->player.view[k]);
      j++;
      k--;
    }
    max--;
    i++;
  }
}

int		**set_minimap(void)
{
  int		**minimap;
  int		i;
  int		j;

  if ((minimap = malloc((g_core->player.level + 2) * sizeof(int *))) == NULL)
    return (NULL);
  i = 0;
  while (i <= g_core->player.level)
  {
    if ((minimap[i] = malloc((g_core->player.level * 2 + 2)
    * sizeof(int))) == NULL)
			return (NULL);
    j = 0;
    while (j <= g_core->player.level * 2 + 1)
    {
      minimap[i][j] = -1;
      j++;
    }
    i++;
  }
  minimap[i] = NULL;
  complete_minimap(minimap);
  return (minimap);
}
