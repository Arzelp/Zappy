/*
** get_player.c for get player in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 13:47:22 2017 Frederic Oddou
** Last update Fri Jun 16 23:23:54 2017 Frederic Oddou
*/

#include <string.h>
#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		get_player(void)
{
  char		buffer[BUFFER_SIZE];
  char		*line1;
  char		*line2;

  if (!receive_msg(buffer, BUFFER_SIZE) || strcmp(buffer, "WELCOME"))
    return (false);
  if (!send_msg(g_core->name_team))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE))
    return (false);
  if ((line1 = strtok(buffer, "\n")) == NULL || !is_nbr(line1))
    return (false);
  g_core->player.client_num = atoi(line1);
  if ((line1 = strtok(NULL, "\n")) == NULL ||
      (line2 = strtok(line1, " ")) == NULL || !is_nbr(line2))
    return (false);
  g_core->map_size[POS_X] = atoi(line2);
  if ((line2 = strtok(NULL, " ")) == NULL || !is_nbr(line2))
    return (false);
  g_core->map_size[POS_Y] = atoi(line2);
  return (true);
}
