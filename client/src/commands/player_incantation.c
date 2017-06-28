/*
** player_incantation.c for incantation in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:13:17 2017 Frederic Oddou
** Last update Tue Jun 27 20:45:20 2017 Paskal Arzel
*/

#include <string.h>
#include <stdio.h>
#include "core.h"
#include "utils.h"

bool		player_incantation(const char *str)
{
  char		buffer[BUFFER_SIZE];

  printf("[Incantation] On entre dans ce fdp.\n");
  if (!send_msg("Incantation"))
    return (false);
  printf("[Incantation] Envoyé le message fdp. Maintenant on attend.\n");
  if (!receive_msg(buffer, BUFFER_SIZE) || is_answer_ko(buffer))
    {
      debug_message_error("Incantation", str, buffer);
      return (false);
    }
  printf("[Incantation] Recu 1/2 \"%s\".\n", buffer);
  if (strcmp(buffer, "Elevation underway"))
    {
      debug_message_error("Incantation", str, buffer);
      return (false);
    }
  printf("[Incantation] On a bien passé la première step, maintenant on attend un nouveau message de ce fdp.\n");
  if (!receive_msg(buffer, BUFFER_SIZE))
    {
      debug_message_error("Incantation", str, buffer);
      return (false);
    }
  printf("[Incantation] Recu 2/2 \"%s\".\n", buffer);
  sscanf(buffer, "Current level: %d", &g_core->player.level);
  printf("[Incantation] Finaly avec %d\n", g_core->player.level);
  debug_message_confirm("Incantation", str, NULL);
  return (true);
}
