/*
** player_fork.c for fork in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:22:49 2017 Frederic Oddou
** Last update Sun Jun 18 18:17:22 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		player_fork(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Fork"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    {
      debug_message_error("Fork", str, NULL);
      return (false);
    }
  debug_message_confirm("Fork", str, NULL);
  return (true);
}
