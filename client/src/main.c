/*
** main.c for lol in /client/src/
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
** Last update Tue Jun 27 23:19:19 2017 Frederic Oddou
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "core.h"
#include "parse.h"

t_core	*g_core = NULL;
t_elem	g_elem[] = {
  {1, "linemate"},
  {2, "deraumere"},
  {3, "sibur"},
  {4, "mendiane"},
  {5, "phiras"},
  {6, "thystame"},
  {7, "food"},
  {-1, NULL}
};

int		main(int ac, char **av)
{
  t_core	core;

  core_init(&core);
  if (!parse(ac, av))
    {
      core_usage(av[0]);
      return (EXIT_FAILURE);
    }
  if (!open_socket() || !get_player())
    return (EXIT_FAILURE);
  ia_main();
  core_destruct();
  return (EXIT_SUCCESS);
}
