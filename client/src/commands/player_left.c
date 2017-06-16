/*
** player_left.c for left in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 14:21:25 2017 Frederic Oddou
** Last update Fri Jun 16 14:23:54 2017 Frederic Oddou
*/

#include "core.h"
#include "utils.h"

bool		player_left(const char *str)
{
  char		buffer[BUFFER_SIZE];

  (void)str;
  if (!send_msg("Left"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    return (false);
  return (true);
}
