/*
** parse_arg.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:32:34 2017 Arthur Josso
** Last update Tue Jun  6 14:58:05 2017 Arthur Josso
*/

#include "core.h"

static void	set_default_values()
{
  g_server->port = 4242;
}

bool	parse_arg(int ac, char **av)
{
  (void)ac;
  (void)av;
  set_default_values();
  return (true);
}
