/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:01:08 2017 Arthur Josso
** Last update Wed Jun 28 14:06:12 2017 Arthur Josso
*/

#include <netdb.h>
#include <poll.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include "core.h"

static void		accept_client()
{
  static bool		too_much_clients = false;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			fd_client;

  s_in_size = sizeof(s_in_client);
  fd_client = accept(g_server->fd, (struct sockaddr*)&s_in_client, &s_in_size);
  if (fd_client == -1)
    {
      if (errno == EINTR)
	return;
      if (errno != EMFILE && errno != ENFILE)
	fat_err("accept");
      if (!too_much_clients)
	warn("%s", "accept");
      too_much_clients = true;
    }
  else
    {
      client_add(fd_client);
      too_much_clients = false;
    }
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

static bool	kill_everybody(t_client *client)
{
  client->callback = &client_entity_fini;
  return (true);
}

static void	secured_poll()
{
  t_poll	*fd_list;
  nfds_t	list_size;
  uint32_t	i;

  fd_list = fd_list_get();
  list_size = fd_list_get_nb();
  if (poll(fd_list, list_size, 0) == -1)
    {
      if (errno == EINTR)
	{
	  i = 0;
	  while (i < list_size)
	    fd_list[i++].revents = 0;
	}
      else
	fat_err("poll");
    }
}

void	run_server()
{
  while (!is_there_a_winner())
    {
      secured_poll();
      if (fd_list_get_revents(g_server->fd) & POLLIN)
	accept_client();
      client_poll_handler();
      client_for_each(&exec_client_behavior);
      egg_check_hatch();
      usleep(500);
    }
  client_for_each(&kill_everybody);
  while (client_get_nbr() > 0)
    {
      secured_poll();
      client_poll_handler();
      client_for_each(&exec_client_behavior);
      usleep(500);
    }
}
