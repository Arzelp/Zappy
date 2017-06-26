/*
** player_fork.c for fork in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:22:49 2017 Frederic Oddou
** Last update Mon Jun 26 14:56:22 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <unistd.h>
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
