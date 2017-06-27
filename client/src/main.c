/*
** main.c for lol in /client/src/
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
<<<<<<< HEAD
** Last update Tue Jun 27 20:26:43 2017 Paskal Arzel
=======
** Last update Tue Jun 27 20:25:15 2017 Frederic Oddou
>>>>>>> fb51422e543af09f82c74986c9ee12ca6855c5e1
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
  ia_main();
  close_socket();
  return (EXIT_SUCCESS);
}
