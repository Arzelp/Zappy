/*
** send_msg.c for send in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 13:24:53 2017 Frederic Oddou
** Last update Fri Jun 16 13:34:23 2017 Frederic Oddou
*/

#include <sys/socket.h>
#include <stdio.h>
#include "core.h"

bool		send_msg(const char *str)
{
  char		buffer[BUFFER_SIZE];
  int		size;

  if (str == NULL)
    return (false);
  if ((size = snprintf(buffer, BUFFER_SIZE, "%s\n", str)) <= 0)
    return (false);
  if (send(g_core->socket_fd, buffer, size, MSG_NOSIGNAL) == -1)
    {
      perror("send");
      return (false);
    }
  return (true);
}
