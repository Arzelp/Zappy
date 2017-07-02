/*
** teamplay.c for teamplay in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 16:18:45 2017 Paskal Arzel
** Last update Sun Jul  2 16:39:59 2017 Paskal Arzel
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

bool		manage_message(void)
{
  t_message	message;

  g_core->player.cd_captain -= (g_core->player.cd_captain) ? 1 : 0;
  if (g_core->player.inventory[FOOD] < MIN_SAFE_FOOD ||
      g_core->player.level < 2)
  {
    printf("I won't teamplay.\n");
    return (false);
  }
  if (!check_message(&message))
    {
      if (g_core->player.cd_captain)
				return (false);
      printf("I'm the captain.\n");
      lead_team();
      g_core->player.cd_captain = CD_CAPTAIN + rand() % CD_CAPTAIN;
      return (true);
    }
  printf("I'm not the captain :( .\n");
  listen_calls(&message);
  return (true);
}
