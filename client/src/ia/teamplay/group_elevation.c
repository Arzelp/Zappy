/*
** group_elevation.c for group_elevation in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:04:05 2017 Paskal Arzel
** Last update Sun Jul  2 20:31:26 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "core.h"

static void	call_regroup()
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, REGROUP);
  send_message(msg);
}

static void	send_ok(void)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, "ok go drop.");
  send_message(msg);
}

static bool	loot_all(void)
{
  int					i;
  bool				ended;
  const t_elevation	*need;
  time_t			start;

  need = elevation_get_infos_lvl(0);
  start = time(NULL);
  ended = false;
  while (!ended && !call_timeout(start, STANDARD_TIMEOUT))
  {
    i = 0;
    player_look(NULL);
    while (i < FOOD)
    {
      if ((int)need->object[i] > g_core->player.inventory[i])
	    	i = FOOD + 1;
      i++;
    }
    ended = (i == FOOD) ? true : false;
    loot(g_core->player.view[0]);
  }
  if (!ended && call_timeout(start, STANDARD_TIMEOUT))
    return (false);
  return (true);
}

static void	send_confirmation(void)
{
  char		msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, "loot ok.");
  send_message(msg);
}

void	group_elevation(t_message	*message)
{
  call_regroup(message);
  g_core->player.need_player = get_nb_players();
  while (!has_players(g_core->player.need_player))
    {
      player_look(NULL);
      force_loot(g_core->player.view[0]);
      player_set("food");
      player_set("food");
      player_set("food");
      send_ping();
      if (!wait_pongs(message))
        return;
    }
  send_ping();
  if (!wait_pongs(message))
    return;
  send_ok();
  if (loot_all() == false)
    return;
  send_confirmation();
  level_up_captain();
}
