/*
** player_connect_nbr.c for connect nbr in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:24:07 2017 Frederic Oddou
** Last update Sun Jun 18 18:15:57 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		player_connect_nbr(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Connect_nbr"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_nbr(buffer))
    {
      debug_message_error("Connect_nbr", str, buffer);
      return (false);
    }
  g_core->player.connect_nbr = atoi(buffer);
  debug_message_confirm("Connect_nbr", str, buffer);
  return (true);
}
