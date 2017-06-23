/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:01:08 2017 Arthur Josso
** Last update Fri Jun 23 18:54:55 2017 Arthur Josso
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
  if (client->type == ENTITY_PLAYER)
    {
      if (player_is_dead(client->entity))
	client->callback = &client_entity_fini;
    }
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
      egg_check_hatch();
      usleep(500);
    }
}
