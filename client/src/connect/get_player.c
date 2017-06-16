/*
** get_player.c for get player in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 13:47:22 2017 Frederic Oddou
** Last update Fri Jun 16 13:55:22 2017 Frederic Oddou
*/

#include <string.h>
#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		get_player(void)
{
  char		buffer[BUFFER_SIZE];
  char		*str;

  if (!receive_msg(buffer, BUFFER_SIZE) || strcmp(buffer, "WELCOME"))
    return (false);
  if (!send_msg(g_core->name_team))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_nbr(buffer))
    return (false);
  g_core->player.client_num = atoi(buffer);
  if (!receive_msg(buffer, BUFFER_SIZE))
    return (false);
  if ((str = strtok(buffer, " ")) == NULL || !is_nbr(str))
    return (false);
  g_core->player.pos[POS_X] = atoi(str);
  if ((str = strtok(NULL, " ")) == NULL || !is_nbr(str))
    return (false);
  g_core->player.pos[POS_Y] = atoi(str);
  return (true);
}
