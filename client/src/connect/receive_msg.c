/*
** receive_msg.c for receive_msg in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 13:34:54 2017 Frederic Oddou
** Last update Tue Jun 27 23:26:18 2017 Frederic Oddou
*/

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "core.h"

bool		receive_msg(char *str, size_t len)
{
  ssize_t	size;
  size_t	i;
  char		c;

  i = 0;
  bzero(str, len);
  while (i < len &&
	 (size = recv(g_core->socket_fd, &c, 1, 0)) > 0 && c != '\n')
    str[i++] = c;
  if (size == -1)
    {
      perror("recv");
      return (false);
    }
  if (!strcmp(str, "dead"))
    {
      fprintf(stderr, "Client die :(\n");
      core_destruct();
      exit(EXIT_SUCCESS);
    }
  return (true);
}
