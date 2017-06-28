/*
** set_rush.c for set_rush.c in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Jun 21 16:09:27 2017 Paskal Arzel
** Last update Tue Jun 27 19:15:56 2017 Paskal Arzel
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

static void go_rush(int **minimap, int primary, int secondary)
{
  int		turns;
  t_pos	position;

  position.x = 0;
  position.y = 1;
  turns = 0;
  loot_case(minimap[g_core->player.level][g_core->player.level]);
  player_forward(NULL);
  loot_case(minimap[g_core->player.level - position.y][g_core->player.level]);
  while (turns < g_core->player.level)
  {
    check_and_move(minimap, &position, primary, secondary);
    elevate();
    printf("new turn\n");
    turns++;
  }
}

static void	planify(int **minimap)
{
  int primary;
  int secondary;

  primary = select_primary();
  secondary = select_secondary(primary);
  go_rush(minimap, primary, secondary);
}

bool	set_rush(void)
{
  int		**minimap;

  if ((minimap = set_minimap()) == NULL)
    return (false);
  planify(minimap);
  return (true);
}
