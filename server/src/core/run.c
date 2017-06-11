/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:01:08 2017 Arthur Josso
** Last update Fri Jun  9 14:39:08 2017 Arthur Josso
*/

#include <netdb.h>
#include <poll.h>
#include <unistd.h>
#include "core.h"

static void		accept_client()
{
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			fd_client;

  s_in_size = sizeof(s_in_client);
  fd_client = accept(g_server->fd, (struct sockaddr*)&s_in_client, &s_in_size);
  if (fd_client == -1)
    fat_err("accept");
  client_add(fd_client);
}

static bool	exec_client_behavior(t_client *client)
{
  return (client->callback(client->entity));
}

void	run_server()
{
  while (1)
    {
      if (poll(fd_list_get(), fd_list_get_nb(), -1) == -1)
	fat_err("poll");
      if (fd_list_get_revents(g_server->fd) & POLLIN)
	accept_client();
      client_poll_handler();
      client_for_each(&exec_client_behavior);
      usleep(5000);
    }
}
