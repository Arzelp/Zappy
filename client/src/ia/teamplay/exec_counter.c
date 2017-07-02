/*
** exec_counter.c for exec_counter in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 06:31:41 2017 Paskal Arzel
** Last update Sun Jul  2 18:18:18 2017 Paskal Arzel
*/

#include <string.h>
#include <stdio.h>
#include "core.h"

bool	exec_counter(void)
{
  char	msg[BUFFER_SIZE];
  int		i;

  snprintf(msg, BUFFER_SIZE, "%s %d N Ressources : ", g_core->name_team,
  g_core->player.level);
  i = 0;
  while (i <= FOOD)
  {
    snprintf(msg + strlen(msg), BUFFER_SIZE - strlen(msg),
	     "%c", (g_core->player.inventory[i] > 9)
       ? '9' : g_core->player.inventory[i] + '0');
    i++;
  }
  send_message(msg);
  return (true);
}
