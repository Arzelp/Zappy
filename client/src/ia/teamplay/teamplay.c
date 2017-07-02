/*
** teamplay.c for teamplay in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 16:18:45 2017 Paskal Arzel
** Last update Sun Jul  2 20:29:27 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "core.h"

bool		check_message(t_message *message)
{
  const char	*data;

  player_inventory(NULL);
  if (memset(message->key, '\0', KEY_SIZE) == NULL ||
      memset(message->core, '\0', BUFFER_SIZE) == NULL)
    return (false);
  while ((data = g_core->queue.front(&g_core->queue)))
  {
    g_core->queue.pop(&g_core->queue);
    if (!strncmp(data, "message ", strlen("message ")))
    {
      read_message(message, data);
      return (true);
    }
  }
  return (false);
}

static void	clear_queue(void)
{
  while (g_core->queue.front(&g_core->queue))
    g_core->queue.pop(&g_core->queue);
}

bool		manage_message(void)
{
  t_message	message;

  g_core->player.ended_tp = false;
  g_core->player.cd_captain -= (g_core->player.cd_captain) ? 1 : 0;
  if (g_core->player.inventory[FOOD] < MIN_SAFE_FOOD ||
      g_core->player.level < 2)
    return (false);
  g_core->player.need_player = get_nb_players();
  if (!check_message(&message))
    {
      if (g_core->player.cd_captain)
				return (false);
      lead_team();
      g_core->player.cd_captain = CD_CAPTAIN + rand() % CD_CAPTAIN;
      clear_queue();
      return (true);
    }
  listen_calls(&message);
  clear_queue();
  return (true);
}
