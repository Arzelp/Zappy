/*
** player_forward.c for forward in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 14:13:20 2017 Frederic Oddou
** Last update Fri Jun 16 14:24:13 2017 Frederic Oddou
*/

#include "core.h"
#include "utils.h"

bool		player_forward(const char *str)
{
  char		buffer[BUFFER_SIZE];

  (void)str;
  if (!send_msg("Forward"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    return (false);
  return (true);
}
