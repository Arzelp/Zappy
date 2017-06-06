/*
** main.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
** Last update Tue Jun  6 15:46:34 2017 Arthur Josso
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "core.h"

t_server	*g_server = NULL;

static void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      fprintf(stderr, "\nClosing server...\n");
      exit(0);
    }
}

int		main(int ac, char **av)
{
  t_server	server;

  g_server = &server;
  if (atexit(&cleaner_func) != 0)
    fat_err("atexit");
  if (signal(SIGINT, &sig_handler) == SIG_ERR)
    fat_err("signal");
  if (!parse_arg(ac, av))
    fat_err_custom("parse_arg");
  run_server();
  return (0);
}
