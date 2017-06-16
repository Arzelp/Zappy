/*
** player_right.c for right in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 14:20:50 2017 Frederic Oddou
** Last update Fri Jun 16 14:24:06 2017 Frederic Oddou
*/

#include "core.h"
#include "utils.h"

bool		player_right(const char *str)
{
  char		buffer[BUFFER_SIZE];

  (void)str;
  if (!send_msg("Right"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    return (false);
  return (true);
}
