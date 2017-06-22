/*
** main.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
** Last update Wed Jun 21 14:56:55 2017 Arthur Josso
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include "core.h"

t_server	*g_server = NULL;
t_game		*g_game = NULL;
t_client	*g_client = NULL;

static void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      fprintf(stderr, "\nClosing server...\n");
      exit(0);
    }
}

static int	print_usage(const char *prog_name)
{
  fprintf(stderr, "USAGE: %s -p port -x width -y height " \
          "-n name1 name2 -c nbClients -f freq\n", prog_name);
  fprintf(stderr, "\tport\t\tis the port number\n");
  fprintf(stderr, "\twidth\t\tis the width of the world\n");
  fprintf(stderr, "\theight\t\tis the height of the world\n");
  fprintf(stderr, "\tname1\t\tis the name of the team 1\n");
  fprintf(stderr, "\tname2\t\tis the name of the team 2\n");
  fprintf(stderr, "\tnbClients\tis the number of authorized " \
          "clients per team\n");
  fprintf(stderr, "\tfreq\t\tis the reciprocal of time unit " \
	  "for execution of actions\n");
  return (1);
}

int		main(int ac, char **av)
{
  t_server	server;

  g_server = &server;
  g_game = &server.game;
  srand(getpid() * time(NULL));
  if (atexit(&cleaner_func) != 0)
    fat_err("atexit");
  if (signal(SIGINT, &sig_handler) == SIG_ERR)
    fat_err("signal");
  if (!parse_arg(ac, av))
    return (print_usage(av[0]));
  if (!init_server())
    fat_err_custom("init_server");
  init_map();
  run_server();
  return (0);
}
