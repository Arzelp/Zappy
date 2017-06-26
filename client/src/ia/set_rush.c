/*
** set_rush.c for set_rush.c in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Jun 21 16:09:27 2017 Paskal Arzel
** Last update Mon Jun 26 14:56:38 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

/*void	print_mini(int **minimap)
{
  int i;
  int j;

  i = 0;
  while (minimap[i] != NULL)
  {
    j = 0;
    while (j < g_core->player.level * 2 + 1)
    {
      printf("%d, ", minimap[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
}*/

static void	planify(int **minimap)
{
  (void)minimap;
  select_primary();
}

bool	set_rush(void)
{
  int		**minimap;

  if ((minimap = set_minimap()) == NULL)
    return (false);
  planify(minimap);
  return (true);
}
