/*
** player_incantation.c for incantation in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:13:17 2017 Frederic Oddou
** Last update Tue Jun 27 20:27:03 2017 Paskal Arzel
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
  printf("Incantation response 1/2 : \"%s\"\n", buffer);
  if (strcmp(buffer, "Elevation underway") ||
      !receive_msg(buffer, BUFFER_SIZE))
    return (false);
  printf("Incantation response 2/2 : \"%s\"\n", buffer);
  scanf(buffer, "Current level: %d", &g_core->player.level);
  debug_message_confirm("Incantation", str, NULL);
  return (true);
}
