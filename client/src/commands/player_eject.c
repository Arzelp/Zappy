/*
** player_eject.c for eject in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:21:02 2017 Frederic Oddou
** Last update Sat Jun 17 22:21:56 2017 Frederic Oddou
*/

#include "core.h"
#include "utils.h"

bool		player_eject(const char *str)
{
  char		buffer[BUFFER_SIZE];

  (void)str;
  if (!send_msg("Eject"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    return (false);
  return (true);
}
