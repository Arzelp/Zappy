/*
** client_manager.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server/src/core
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:27:14 2017 Arthur Josso
** Last update Tue Jun  6 16:27:15 2017 Arthur Josso
*/

#include <stdio.h>
#include <string.h>
#include "core.h"

static t_poll_func poll_funcs[] =
  {
    {POLLERR, &client_rm},
    {POLLHUP, &client_rm},
    {POLLNVAL, &client_rm},
    {POLLIN, &read_on_client},
    {POLLOUT, &write_on_client},
    {0, NULL}
  };

void		client_add(int fd)
{
  t_client	*new;

  new = cleaner_malloc(sizeof(t_client));
  client_init(new, fd);
  if (g_server->clients)
    g_server->clients->prev = new;
  g_server->clients = new;
  fprintf(stderr, "New client on fd : %d\n", fd);
}

bool		client_rm(t_client *client)
{
  if (client->prev)
    client->prev->next = client->next;
  if (client->next)
    client->next->prev = client->prev;
  if (g_server->clients == client)
    g_server->clients = client->next;
  client_fini(client);
  fprintf(stderr, "Leaving client on fd : %d\n", client->fd);
  cleaner_rm_addr(client);
  return (false);
}

void		client_for_each(t_client_callback callback)
{
  t_client	*client;
  t_client	*tmp;

  client = g_server->clients;
  while (client)
    {
      tmp = client->next;
      callback(client);
      client = tmp;
    }
}

void		client_poll_handler()
{
  t_client      *client;
  t_client      *tmp;
  size_t	i;

  client = g_server->clients;
  while (client)
    {
      tmp = client->next;
      i = 0;
      while (poll_funcs[i].func)
	{
	  if (fd_list_get_revents(client->fd) & poll_funcs[i].event)
	    {
	      if ((poll_funcs[i].func)(client) == false)
		break;
	    }
	  i++;
	}
      client = tmp;
    }
}
