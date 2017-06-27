/*
** main.c for lol in /client/src/
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
** Last update Tue Jun 27 20:26:43 2017 Paskal Arzel
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

void		test_server_features(void)
{
  printf("Trying 12 actions:\n");
  if (player_right(NULL))
    printf("1- Player turned right.\n");
  if (player_left(NULL))
    printf("2- Player turned left.\n");
  if (player_forward(NULL))
    printf("3- Player forward.\n");
  if (player_broadcast("message"))
    printf("4- Player broadcast.\n");
  if (player_look(NULL))
    printf("5- Look.\n");
  if (player_inventory(NULL))
    printf("6- Inventory.\n");
  if (player_take("food"))
    printf("7- Take food.\n");
  if (player_set("food"))
    printf("8- Set food.\n");
  if (player_connect_nbr(NULL))
    printf("9- Connect_nbr.\n");
  if (player_eject(NULL))
    printf("10- Eject.\n");
  if (player_fork(NULL))
    printf("11- Fork.\n");
  if (player_incantation(NULL))
    printf("12- Incantation.\n");
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
  test_server_features();
  ia_main();
  close_socket();
  return (EXIT_SUCCESS);
}
