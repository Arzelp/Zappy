/*
** tool.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 23 20:37:06 2017 Arthur Josso
** Last update Fri Jun 23 20:38:30 2017 Arthur Josso
*/

#include "core.h"

void		client_for_each(t_client_callback callback)
{
  t_client	*client;
  t_client	*tmp;
  t_client	*save;

  save = g_client;
  client = g_server->clients;
  while (client)
    {
      tmp = client->next;
      g_client = client;
      if (callback(client) == false)
        client_rm(client);
      client = tmp;
    }
  g_client = save;
}

size_t		client_get_nbr()
{
  t_client	*client;
  size_t	nbr;

  nbr = 0;
  client = g_server->clients;
  while (client)
    {
      nbr++;
      client = client->next;
    }
  return (nbr);
}
