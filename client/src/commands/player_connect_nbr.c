/*
** player_connect_nbr.c for connect nbr in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:24:07 2017 Frederic Oddou
** Last update Wed Jun 28 10:03:29 2017 Frederic Oddou
*/

#include <stdlib.h>
#include <ctype.h>
#include "core.h"
#include "utils.h"

static bool	player_connect_nbr_answer_check(const char *str)
{
  if (is_nbr(str) || is_answer_ko(str))
    return (true);
  return (false);
}

bool		player_connect_nbr(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Connect_nbr"))
    return (false);
  if (!cmd_checker(buffer, &player_connect_nbr_answer_check) ||
      !is_nbr(buffer))
    {
      debug_message_error("Connect_nbr", str, buffer);
      return (false);
    }
  g_core->player.connect_nbr = atoi(buffer);
  debug_message_confirm("Connect_nbr", str, buffer);
  return (true);
}
