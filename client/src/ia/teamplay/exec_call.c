/*
** exec_call.c for exec_call in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 05:58:59 2017 Paskal Arzel
** Last update Sun Jul  2 20:30:05 2017 Paskal Arzel
*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "core.h"

bool	call_confirmed(t_message *message)
{
  char				msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C call confirmed.", g_core->name_team,
  g_core->player.level);
  if (strcmp(msg, message->core))
    return (false);
  return (true);
}

bool	exec_call(void)
{
  t_message		message;
  char				msg[BUFFER_SIZE];
  time_t			start;

  snprintf(msg, BUFFER_SIZE, "%s %d N call accepted.", g_core->name_team,
  g_core->player.level);
  send_message(msg);
  start = time(NULL);
  check_message(&message);
  while (!call_confirmed(&message) && !call_timeout(start, STANDARD_TIMEOUT))
    check_message(&message);
  if (call_timeout(start, STANDARD_TIMEOUT) && !call_confirmed(&message))
    return (false);
  return (true);
}
