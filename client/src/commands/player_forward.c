/*
** player_forward.c for forward in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 14:13:20 2017 Frederic Oddou
** Last update Tue Jun 27 20:47:37 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		player_forward(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Forward"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || is_answer_ko(buffer))
    {
      debug_message_error("Forward", str, NULL);
      return (false);
    }
  debug_message_confirm("Forward", str, NULL);
  return (true);
}
