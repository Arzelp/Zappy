/*
** parse_arg.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:32:34 2017 Arthur Josso
** Last update Fri Jun  9 15:01:22 2017 Arthur Josso
*/

#include <unistd.h>
#include <stdio.h>
#include "core.h"

static t_parse_opt parse_opt[] =
  {
    {'p', &parse_p_opt},
    {'x', &parse_x_opt},
    {'y', &parse_y_opt},
    {'n', &parse_n_opt},
    {'c', &parse_c_opt},
    {'t', &parse_t_opt},
    {'\0', NULL}
  };

static char **g_av;

bool    parse_n_opt(t_parse_action action)
{
  int	idx;

  if (action == PARSE_INIT)
    {
      g_game->team[0].name = NULL;
      g_game->team[1].name = NULL;
    }
  else if (action == PARSE_FILL)
    {
      idx = 0;
      while (g_av[idx] != optarg)
	idx++;
      idx++;
      g_game->team[0].name = optarg;
      if (g_av[idx] == NULL || g_av[idx][0] == '-' || g_av[idx][0] == '\0')
	return (false);
      g_game->team[1].name = g_av[idx];
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->team[0].name == NULL || g_game->team[1].name == NULL)
        return (false);
    }
  return (true);
}

static void	set_init_values()
{
  g_server->fd = -1;
  g_server->clients = NULL;
  g_game->team[0].players =
    cleaner_malloc(g_game->max_players * sizeof(t_player*));
  g_game->team[0].nbr_players = 0;
  g_game->team[1].players =
    cleaner_malloc(g_game->max_players * sizeof(t_player*));
  g_game->team[1].nbr_players = 0;
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
  while ((opt = getopt(ac, av, "p:x:y:n:c:t:")) != -1)
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
  g_av = av;
  if (!for_each_parse_func(PARSE_INIT, -1))
    return (false);
  if (!check_opts(ac, av))
    return (false);
  if (!for_each_parse_func(PARSE_CHECK, -1))
    return (false);
  set_init_values();
  return (true);
}
