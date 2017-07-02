/*
** exec_regroup.c for exec_regroup in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:35:15 2017 Paskal Arzel
** Last update Sun Jul  2 16:11:36 2017 Paskal Arzel
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "core.h"

static bool	wait_ping(t_message	*message)
{
  char		msg[BUFFER_SIZE];
  time_t	start;

  start = time(NULL);
  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "ping.");
  while (!call_timeout(start, STANDARD_TIMEOUT))
    {
      check_message(message);
      if (!strcmp(msg, message->core))
				return (true);
    }
  return (false);
}

static void	send_pong()
{
  char		msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s N %s", g_core->name_team, "pong.");
  send_message(msg);
}

static bool	check_arrived(void)
{
  player_look(NULL);
  if (count_players() >= 2
	&& calc_value(g_core->player.view[0]) == 3000000)
		return (true);
  return (false);
}

static bool	wait_everyone(t_message *message)
{
  int		timer;
  char	msg[BUFFER_SIZE];
  bool	ended;

  if (has_players(NB_PLAYER_CALL))
    return (true);
  ended = false;
  timer = 12;
  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "ok go drop.");
  while (!ended && timer)
  {
    check_message(message);
    printf("%s\n", message->core);
    if (!strcmp(msg, message->core))
			return (true);
    send_pong();
    if (!wait_ping(message))
      ended = true;
    if (has_players(NB_PLAYER_CALL))
      return (true);
    timer--;
  }
  printf("je suis la mdr.\n");
  return (false);
}

bool	exec_regroup(void)
{
  t_message	message;
  bool			ended;

  printf("Regrouping.\n");
  if (!wait_ping(&message))
    return (false);
  ended = check_arrived();
  while (!ended)
  {
    printf("not instant.   ");
    printf("message : %s\n", message.core);
    change_dir(&message);
    player_forward(NULL);
    send_pong();
    if (!wait_ping(&message))
			return (false);
    ended = check_arrived();
  }
  printf("coucou.\n");
  if (wait_everyone(&message) == false)
    return (false);
  send_pong();
  printf("Seems like everything is ok for me.\n");
  drop_all();
  return (true);
}
