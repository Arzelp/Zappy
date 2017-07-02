/*
** level_up.c for levlu_p in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 17:02:25 2017 Paskal Arzel
** Last update Sun Jul  2 20:28:36 2017 Paskal Arzel
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "core.h"

static bool	confirm_lvl()
{
  time_t start;
  char	msg[BUFFER_SIZE];
  bool	ended;
  t_message	message;

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
	   g_core->player.level, "lvl confirmed.");
  start = time(NULL);
  ended = false;
  while (!call_timeout(start, STANDARD_TIMEOUT) && !ended)
  {
    check_message(&message);
    if (!strcmp(message.core, msg))
			return (true);
  }
  return (false);
}

static void	lvl_confirm()
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
	   g_core->player.level - 1, "lvl confirmed.");
  send_message(msg);
}

void	level_up_noob(void)
{
  time_t	start;

  start = time(NULL);
  while (!call_timeout(start, STANDARD_TIMEOUT))
    {
    }
  player_look(NULL);
  g_core->player.ended_tp = true;
  if (!confirm_lvl())
    return;
  g_core->player.level++;
  return;
}

void	level_up_captain(void)
{
  int	attempts;
  int prev_lvl;

  prev_lvl = g_core->player.level;
  while (prev_lvl == g_core->player.level && attempts < MAX_ATTEMPTS)
    {
      player_look(NULL);
      loot(g_core->player.view[0]);
      elevate();
      attempts++;
    }
  if (prev_lvl != g_core->player.level)
    lvl_confirm();
}
