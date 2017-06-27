/*
** player_eject.c for eject in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:21:02 2017 Frederic Oddou
** Last update Tue Jun 27 20:48:21 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "core.h"
#include "utils.h"

bool		player_eject(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Eject"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || is_answer_ko(buffer))
    {
      debug_message_error("Eject", str, NULL);
      return (false);
    }
  debug_message_confirm("Eject", str, NULL);
  return (true);
}
