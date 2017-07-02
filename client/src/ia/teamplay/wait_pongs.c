/*
** wait_pongs.c for wait_pongs in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:25:32 2017 Paskal Arzel
** Last update Sun Jul  2 19:48:54 2017 Paskal Arzel
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

static bool	is_pong(t_message	*message)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d N %s", g_core->name_team,
  g_core->player.level, "pong.");
  if (strcmp(msg, message->core))
    return (false);
  return (true);
}

bool	wait_pongs(t_message	*message)
{
  int			count;
  time_t	start;

  count = 1;
  start = time(NULL);
  while (count < g_core->player.need_player
    && !call_timeout(start, STANDARD_TIMEOUT))
  {
    check_message(message);
    count += (int)is_pong(message);
  }
  if (call_timeout(start, STANDARD_TIMEOUT)
  && count < g_core->player.need_player)
    return (false);
  return (true);
}
