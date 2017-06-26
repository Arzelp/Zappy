/*
** parse_arg.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:32:34 2017 Arthur Josso
** Last update Wed Jun 21 14:11:17 2017 Arthur Josso
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "core.h"

static t_parse_opt parse_opt[] =
  {
    {'p', &parse_p_opt},
    {'x', &parse_x_opt},
    {'y', &parse_y_opt},
    {'n', &parse_n_opt},
    {'c', &parse_c_opt},
    {'f', &parse_f_opt},
    {'\0', NULL}
  };

static void	set_init_values()
{
  int		i;

  g_server->fd = -1;
  g_server->clients = NULL;
  i = 0;
  while (g_game->team[i])
    {
      g_game->team[i]->players =
	cleaner_malloc(g_game->max_players_init * sizeof(t_player*));
      g_game->team[i]->nbr_players = 0;
      g_game->team[i]->max_players = g_game->max_players_init;
      i++;
    }
}

static bool	for_each_parse_func(t_parse_action action, char opt)
{
  int		i;

  i = 0;
  while (parse_opt[i].opt)
    {
      if (opt == -1 || parse_opt[i].opt == opt)
        {
          if ((parse_opt[i].func)(action) == false)
            return (false);
        }
      i++;
    }
  return (true);
}

static bool	check_opts(int ac, char **av)
{
  int		opt;

  opterr = 0;
  while ((opt = getopt(ac, av, "p:x:y:n:c:f:")) != -1)
    {
      if (opt == '?')
	return (false);
      if (!for_each_parse_func(PARSE_FILL, opt))
	return (false);
    }
  return (true);
}

bool		parse_arg(int ac, char **av)
{
  memset(g_server, 0, sizeof(t_server));
  parse_team_set_av(av);
  if (!for_each_parse_func(PARSE_INIT, -1))
    return (false);
  if (!check_opts(ac, av))
    return (false);
  if (!for_each_parse_func(PARSE_CHECK, -1))
    return (false);
  set_init_values();
  return (true);
}
