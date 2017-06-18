/*
** player_left.c for left in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 14:21:25 2017 Frederic Oddou
** Last update Sun Jun 18 18:18:03 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		player_left(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Left"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    {
      debug_message_error("Left", str, NULL);
      return (false);
    }
  debug_message_confirm("Left", str, NULL);
  return (true);
}
