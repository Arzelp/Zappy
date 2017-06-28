/*
** player_right.c for right in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 14:20:50 2017 Frederic Oddou
** Last update Wed Jun 28 09:33:39 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		player_right(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Right"))
    return (false);
  if (!cmd_checker(buffer, &cmd_ok_or_ko) || is_answer_ko(buffer))
    {
      debug_message_error("Right", str, NULL);
      return (false);
    }
  debug_message_confirm("Right", str, NULL);
  return (true);
}
