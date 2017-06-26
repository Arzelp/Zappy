/*
** receive_msg.c for receive_msg in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 13:34:54 2017 Frederic Oddou
** Last update Mon Jun 26 15:29:38 2017 arnaud.alies
*/

#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include "core.h"

bool		receive_msg(char *str, size_t len)
{
  ssize_t	size;

  bzero(str, len);
  if ((size = recv(g_core->socket_fd, str, len, 0)) == -1)
    {
      perror("recv");
      return (false);
    }
  if (size > 0 && str[size - 1] == '\n')
    str[size - 1] = '\0';
  return (true);
}
