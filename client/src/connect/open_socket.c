/*
** open_socket.c for socket in /client/src/connect/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 12:01:22 2017 Frederic Oddou
** Last update Fri Jun 16 23:09:39 2017 Frederic Oddou
*/

#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "core.h"

static bool		init_tcp_socket(int *socket_fd)
{
  struct protoent	*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    {
      fprintf(stderr, "getprotobyname failed.\n");
      return (false);
    }
  if ((*socket_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      perror("socket");
      return (false);
    }
  return (true);
}

static void		init_port_socket(const int *tab)
{
  char			buffer[BUFFER_SIZE];

  memset(buffer, '\0', BUFFER_SIZE);
  g_core->port_socket.sin_family = AF_INET;
  g_core->port_socket.sin_port = htons(g_core->port);
  sprintf(buffer, "%d.%d.%d.%d", tab[0], tab[1], tab[2], tab[3]);
  g_core->port_socket.sin_addr.s_addr = inet_addr(buffer);
}

static bool		get_ip(const char *cmd, int *tab)
{
  if (sscanf(cmd, "%d.%d.%d.%d", &tab[0], &tab[1], &tab[2],
	     &tab[3]) != 4)
    {
      if (strcmp(cmd, "localhost"))
	return (false);
      tab[0] = 127;
      tab[1] = 0;
      tab[2] = 0;
      tab[3] = 1;
    }
  return (true);
}

bool			open_socket(void)
{
  int			tab[4];

  if (!get_ip(g_core->host, tab) || !init_tcp_socket(&g_core->socket_fd))
    return (false);
  init_port_socket(tab);
  if (connect(g_core->socket_fd, (const struct sockaddr *)&g_core->port_socket,
	      sizeof(struct sockaddr)) == -1)
    {
      perror("connect");
      return (false);
    }
  return (true);
}
