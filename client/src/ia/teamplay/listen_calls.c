/*
** listen_calls.c for listen_calls in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat Jul  1 23:40:08 2017 Paskal Arzel
** Last update Sun Jul  2 15:45:57 2017 Paskal Arzel
*/

#include <string.h>
#include <stdio.h>
#include <time.h>
#include "core.h"

static bool	receive_command(t_message *message)
{
  char	msg[BUFFER_SIZE];

  if (message == NULL)
    return (false);
  if (message->core[0] == '\0')
    return (false);
  snprintf(msg, BUFFER_SIZE, "%s C ", g_core->name_team);
  if (!strncmp(message->core, msg, strlen(msg)))
    return (true);
  return (false);
}

static bool	is_ended(t_message *message)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "ended.");
  if (!strcmp(msg, message->core))
    return (true);
  return (false);
}

void	listen_calls(t_message *message)
{
  time_t	start;
  bool		ended;

  ended = false;
  while (!ended)
  {
    if (execute_call(message, strlen(g_core->name_team) + 3) == true)
			printf("call executed.\n");
    else
			printf("no call or failed.\n");
    start = time(NULL);
    check_message(message);
    while (!receive_command(message) && !call_timeout(start, STANDARD_TIMEOUT))
      check_message(message);
    if (call_timeout(start, STANDARD_TIMEOUT))
			ended = true;
    if (is_ended(message))
			ended = true;
  }
}
