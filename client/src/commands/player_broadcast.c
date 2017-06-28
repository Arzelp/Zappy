/*
** player_broadcast.c for broadcast in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 14:25:07 2017 Frederic Oddou
** Last update Wed Jun 28 09:38:31 2017 Frederic Oddou
*/

#include <stdio.h>
#include <string.h>
#include "core.h"
#include "utils.h"

bool		player_broadcast(const char *str)
{
  char		buffer[BUFFER_SIZE];

  snprintf(buffer, BUFFER_SIZE, "Broadcast %s", str);
  if (!send_msg(buffer))
    return (false);
  if (!cmd_checker(buffer, &cmd_ok_or_ko) || is_answer_ko(buffer))
    {
      debug_message_error("Broadcast", str, NULL);
      return (false);
    }
  debug_message_confirm("Broadcast", str, NULL);
  return (true);
}
