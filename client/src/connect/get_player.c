/*
** get_player.c for get player in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 13:47:22 2017 Frederic Oddou
** Last update Mon Jun 26 16:33:09 2017 Frederic Oddou
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "core.h"
#include "utils.h"

static void	confirm_new_player()
{
  if (DEBUG)
    {
      fprintf(stderr, "Player from the team %s entering on the game.\n",
	      g_core->name_team);
      fprintf(stderr, "The size of the map is %d:%d and the client number "
	      "is %d.\n", g_core->map_size[POS_X], g_core->map_size[POS_Y],
	      g_core->player.client_num);
    }
}

bool		get_player(void)
{
  char		buffer[BUFFER_SIZE];
  char		*line2;

  if (!receive_msg(buffer, BUFFER_SIZE) || strcmp(buffer, "WELCOME"))
    return (false);
  if (!send_msg(g_core->name_team))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE))
    return (false);
  g_core->player.client_num = atoi(buffer);
  if (!receive_msg(buffer, BUFFER_SIZE))
    return (false);
  if ((line2 = strtok(buffer, " ")) == NULL || !is_nbr(line2))
    return (false);
  g_core->map_size[POS_X] = atoi(line2);
  if ((line2 = strtok(NULL, " ")) == NULL || !is_nbr(line2))
    return (false);
  g_core->map_size[POS_Y] = atoi(line2);
  g_core->player.level = 1;
  confirm_new_player();
  return (true);
}
