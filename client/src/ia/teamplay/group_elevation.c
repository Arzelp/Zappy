/*
** group_elevation.c for group_elevation in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:04:05 2017 Paskal Arzel
** Last update Sun Jul  2 17:09:23 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "core.h"

static void	call_regroup(t_message *message)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, REGROUP);
  send_message(msg);
}

static void	send_ok(void)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "ok go drop.");
  send_message(msg);
  printf("message sent : %s\n", msg);
}

static bool	loot_all(void)
{
  int					i;
  bool				ended;
  t_elevation	*need;
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
      if (need->object[i] > g_core->player.inventory[i])
	    	i = FOOD + 1;
      i++;
    }
    ended = (i == FOOD) ? true : false;
    printf("%s\n", g_core->player.view[0]);
    loot(g_core->player.view[0]);
  }
  if (ended)
    printf("ok loot\n");
  if (!ended && call_timeout(start, STANDARD_TIMEOUT))
    return (false);
  return (true);
}

static void	send_confirmation(void)
{
  char		msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "loot ok.");
  send_message(msg);
  printf("Confirmation sent.\n");
}

void	group_elevation(t_message	*message)
{
  printf("in group elevation\n");
  call_regroup(message);
  printf("regroup called\n");
  while (!has_players(NB_PLAYER_CALL))
    {
      player_look(NULL);
      force_loot(g_core->player.view[0]);
      player_set("food");
      player_set("food");
      player_set("food");
      send_ping();
      if (!wait_pongs(message))
      {
        printf("Pongs aren't ok");
        return;
      }
      printf("new turn \n");
    }
  printf("lol\n");
  send_ping();
  if (!wait_pongs(message))
    return;
  send_ok();
  printf("We're together.\n");
  printf("my case : %s\n", g_core->player.view[0]);
  if (loot_all() == false)
    return;
  send_confirmation();
  level_up_captain();
}
