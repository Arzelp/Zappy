/*
** main.c for lol in /client/src/
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
** Last update Thu Jun 29 22:10:43 2017 Paskal Arzel
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

  srand(time(NULL));
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
