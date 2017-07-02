/*
** lead_team.c for lead_team in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat Jul  1 19:29:05 2017 Paskal Arzel
** Last update Sun Jul  2 20:37:26 2017 Paskal Arzel
*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "core.h"

static int		check_counter(t_message *message, int count)
{
  char				msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d N call accepted.", g_core->name_team,
  g_core->player.level);
  if (!strcmp(msg, message->core))
    return (count + 1);
  return (count);
}

static void		send_confirmation(void)
{
  char				msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, "call confirmed.");
  send_message(msg);
}

static bool		send_r(void)
{
  char				msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, "ended.");
  send_message(msg);
  return (false);
}

static bool		start_lead(void)
{
  char				msg[BUFFER_SIZE];
  t_message		message;
  time_t			start;
  int					count;

  start = time(NULL);
  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, CALL);
  send_message(msg);
  count = 1;
  while (count < g_core->player.need_player
    && !call_timeout(start, STANDARD_TIMEOUT))
  {
    check_message(&message);
    count = check_counter(&message, count);
  }
  if (call_timeout(start, STANDARD_TIMEOUT))
    return (false);
  send_confirmation();
  if (!check_ressources(&message))
    return (send_r());
  group_elevation(&message);
  return (true);
}

void		lead_team(void)
{
  if (start_lead() == false)
    return;
}
