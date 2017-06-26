/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:25:30 2017 Arthur Josso
** Last update Mon Jun 26 16:36:27 2017 Arthur Josso
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <strings.h>
#include "core.h"

static void	init_sockaddr(struct sockaddr_in *s_in, uint16_t port)
{
  bzero(s_in, sizeof(*s_in));
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
}

bool			init_server()
{
  struct sockaddr_in	s_in;
  int			enable_reuseaddr;

  g_server->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (g_server->fd == -1)
    fat_err("socket");
  fd_list_add(g_server->fd);
  enable_reuseaddr = 1;
  if (setsockopt(g_server->fd, SOL_SOCKET, SO_REUSEADDR,
		 &enable_reuseaddr, sizeof(int)) == -1)
    fat_err("setsockopt");
  init_sockaddr(&s_in, g_server->port);
  if (bind(g_server->fd, (const struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    fat_err("bind");
  if (listen(g_server->fd, MAX_PENDING_CONNECTIONS) == -1)
    fat_err("listen");
  return (true);
}
