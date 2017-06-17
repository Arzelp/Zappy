/*
** player_fork.c for fork in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:22:49 2017 Frederic Oddou
** Last update Sat Jun 17 22:23:28 2017 Frederic Oddou
*/

#include "core.h"
#include "utils.h"

bool		player_fork(const char *str)
{
  char		buffer[BUFFER_SIZE];

  (void)str;
  if (!send_msg("Fork"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    return (false);
  return (true);
}
