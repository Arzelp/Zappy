/*
** drop_all.c for drop_all in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 14:44:25 2017 Paskal Arzel
** Last update Sun Jul  2 20:36:10 2017 Paskal Arzel
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "core.h"

static bool	wait_confirmation(void)
{
  char	msg[BUFFER_SIZE];
  t_message	message;
  time_t	start;
  bool	ended;

  start = time(NULL);
  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, "loot ok.");
  ended = false;
  while (!ended && !call_timeout(start, STANDARD_TIMEOUT))
  {
    check_message(&message);
    if (!strcmp(msg, message.core))
			ended = true;
  }
  if (call_timeout(start, STANDARD_TIMEOUT))
    return (false);
  return (true);
}

void	drop_all(void)
{
  int	i;
  int	objs;

  i = 0;
  while (i < FOOD)
  {
    objs = g_core->player.inventory[i];
    while (objs)
    {
      player_set(g_elem[i].name);
      objs--;
    }
    i++;
  }
  if (!wait_confirmation())
    return;
  level_up_noob();
}
