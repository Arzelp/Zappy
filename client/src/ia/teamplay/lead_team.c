/*
** lead_team.c for lead_team in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat Jul  1 19:29:05 2017 Paskal Arzel
** Last update Sun Jul  2 15:47:21 2017 Paskal Arzel
*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include "core.h"

static int		check_counter(t_message *message, int count)
{
  char				msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s N call accepted.", g_core->name_team, CALL);
  if (!strcmp(msg, message->core))
    return (count + 1);
  return (count);
}

static void		send_confirmation(void)
{
  char				msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "call confirmed.");
  send_message(msg);
}

static bool		start_lead(void)
{
  char				msg[BUFFER_SIZE];
  const t_elevation *need;
  t_message		message;
  time_t			start;
  int					count;

  start = time(NULL);
  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, CALL);
  send_message(msg);
  need = elevation_get_infos();
  count = 1;
  while (count < NB_PLAYER_CALL && !call_timeout(start, STANDARD_TIMEOUT))
  {
    check_message(&message);
    count = check_counter(&message, count);
  }
  if (call_timeout(start, STANDARD_TIMEOUT))
    return (false);
  send_confirmation();
  if (!check_ressources(&message))
    {
      printf("ressources not ok.\n");
      snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "ended.");
      send_message(msg);
      return (false);
    }
  printf("Ressources ok.\n");
  group_elevation(&message);
  return (true);
}

void		lead_team(void)
{
  if (start_lead() == false)
    return;
}
