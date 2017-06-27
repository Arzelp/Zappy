/*
** player_look.c for look in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 13:25:57 2017 Frederic Oddou
** Last update Tue Jun 27 20:52:41 2017 Frederic Oddou
*/

#include <string.h>
#include "core.h"
#include "utils.h"

static bool	separate(char *buffer)
{
  char		*str;
  size_t	i;

  i = 0;
  str = strtok_single(buffer, ",");
  while (str)
    {
      strcpy(g_core->player.view[i], str);
      str = trim(replace_letter(g_core->player.view[i], ']', '\0'));
      str = strtok_single(NULL, ",");
      i++;
    }
  return (true);
}

bool		player_look(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Look"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE))
    return (false);
  bzero(g_core->player.view, sizeof(g_core->player.view));
  debug_message_confirm("Look", str, buffer);
  separate(buffer + 1);
  return (true);
}
