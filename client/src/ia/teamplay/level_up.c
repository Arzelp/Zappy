/*
** level_up.c for levlu_p in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 17:02:25 2017 Paskal Arzel
** Last update Sun Jul  2 17:11:33 2017 Paskal Arzel
*/

#include <stdio.h>
#include <string.h>
#include "core.h"

void	level_up_noob(void)
{
  time_t	start;
  int			prev_lvl;

  while (g_core->player.level < 3)
    {
      start = time(NULL);
      prev_lvl = g_core->player.level;
      while (prev_lvl == g_core->player.level &&
	     !call_timeout(start, STANDARD_TIMEOUT))
       {
         printf("Waiting level : %d.\n", g_core->player.level);
       }
    }
}

void	level_up_captain(void)
{
  int	attempts;
  int prev_lvl;

  printf("level : %d\n", g_core->player.level);
  while (g_core->player.level < 3)
    {
      attempts = 0;
      prev_lvl = g_core->player.level;
      while (attempts < MAX_ATTEMPTS && prev_lvl == g_core->player.level)
      {
        player_look(NULL);
        loot(g_core->player.view[0]);
        elevate();
        attempts++;
      }
      printf("level : %d\n", g_core->player.level);
    }
}
