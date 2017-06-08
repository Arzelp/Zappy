/*
** client_init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server/src/core
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:27:00 2017 Arthur Josso
** Last update Thu Jun  8 17:47:12 2017 Arthur Josso
*/

#include "core.h"

void	client_init(t_client *client, int fd)
{
  fd_list_add(fd);
  client->fd = fd;
  client->ibuff = cleaner_strcat(NULL, "");
  client->obuff = cleaner_strcat(NULL, "");
  client->entity = NULL;
  client->prev = NULL;
  client->next = g_server->clients;
}

void	client_fini(t_client *client)
{
  fd_list_rm(client->fd);
  cleaner_rm_addr(client->ibuff);
  cleaner_rm_addr(client->obuff);
  if (client->entity)
    cleaner_rm_addr(client->entity);
}
