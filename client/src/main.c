/*
** main.c for lol in /client/src/
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
** Last update Fri Jun 16 13:55:52 2017 Frederic Oddou
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "core.h"

t_core	*g_core = NULL;

static void	init(t_core *core)
{
  bzero(core, sizeof(*core));
  g_core = core;
}

static void	usage(const char *name)
{
  fprintf(stderr, "USAGE: %s -p port -n name -h machine\n", name);
  fprintf(stderr, "\tport\tis the port number\n");
  fprintf(stderr, "\tname\tis the name of the team\n");
  fprintf(stderr, "\tmachine\tis the name of the machine; "
	  "localhost by default\n");
}

int		main(int ac, char **av)
{
  t_core	core;

  init(&core);
  if (!parse(ac, av))
    {
      usage(av[0]);
      return (EXIT_FAILURE);
    }
  if (!open_socket() || !get_player())
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
