/*
** close_socket.c for close socket in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 23:52:54 2017 Frederic Oddou
** Last update Fri Jun 16 23:54:01 2017 Frederic Oddou
*/

#include <unistd.h>
#include "core.h"

bool		close_socket(void)
{
  if (g_core->socket_fd > 0)
    {
      close(g_core->socket_fd);
      return (true);
    }
  return (false);
}
