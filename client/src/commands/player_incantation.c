/*
** player_incantation.c for incantation in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:13:17 2017 Frederic Oddou
** Last update Tue Jun 27 19:52:59 2017 Paskal Arzel
*/

#include <string.h>
#include <stdio.h>
#include "core.h"
#include "utils.h"

bool		player_incantation(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Incantation"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || is_answer_ko(buffer))
    {
      debug_message_error("Incantation", str, NULL);
      return (false);
    }
  scanf(buffer, "Elevation underway\nCurrent level: %d",
	&g_core->player.level);
  debug_message_confirm("Incantation", str, NULL);
  return (true);
}
