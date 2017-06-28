/*
** player_incantation.c for incantation in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:13:17 2017 Frederic Oddou
** Last update Wed Jun 28 14:46:23 2017 Paskal Arzel
*/

#include <string.h>
#include <stdio.h>
#include "core.h"
#include "utils.h"

static bool	player_incantation_answer_check(const char *str)
{
  if (is_answer_ko(str) ||
      !strcmp(str, "Elevation underway") ||
      !strncmp(str, "Current level: ", strlen("Current level: ")))
    return (true);
  return (false);
}

bool		player_incantation(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Incantation"))
    return (false);
  if (!cmd_checker(buffer, &player_incantation_answer_check) ||
      is_answer_ko(buffer) || !strcmp(buffer, "Elevation underway"))
    {
      debug_message_error("Incantation", str, buffer);
      return (false);
    }
  if (!cmd_checker(buffer, &player_incantation_answer_check) ||
      !strncmp(str, "Current level: ", strlen("Current level: ")))
    {
      debug_message_error("Incantation", str, buffer);
      return (false);
    }
  sscanf(buffer, "Current level: %d", &g_core->player.level);
  debug_message_confirm("Incantation", str, NULL);
  return (true);
}
