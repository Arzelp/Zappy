/*
** client_io_cmd.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 17:11:02 2017 Arthur Josso
** Last update Sat Jun 17 14:23:08 2017 Arthur Josso
*/

#include "core.h"

static t_graphic_func	g_func;
static const char	*g_arg;

static bool	callback_for_each_graphic(t_client *client)
{
  if (client->type == ENTITY_GRAPHIC)
    g_func(client->entity, g_arg);
  return (true);
}

void	for_each_graphic(t_graphic_func func, const char *arg)
{
  g_func = func;
  g_arg = arg;
  client_for_each(&callback_for_each_graphic);
}
