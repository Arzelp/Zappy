/*
** parse_arg.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:32:34 2017 Arthur Josso
** Last update Wed Jun  7 15:07:05 2017 Arthur Josso
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

bool    parse_n_opt()
{
  int	idx;

  idx = 0;
  while (g_av[idx] != optarg)
    idx++;
  idx++;
  g_game->team[0].name = optarg;
  if (g_av[idx] == NULL ||
      g_av[idx][0] == '-' ||
      g_av[idx][0] == '\0')
    return (false);
  g_game->team[1].name = g_av[idx];
  return (true);
}

static void	set_default_values()
{
  g_server->port = 4242;
  g_server->fd = -1;
  g_server->clients = NULL;
  g_game->map_size.x = -1;
  g_game->map_size.y = -1;
  g_game->max_players = -1;
  g_game->frequency = -1;
  g_game->team[0].name = NULL;
  g_game->team[1].name = NULL;
}

static bool	check_opts(int ac, char **av)
{
  int		opt;
  int		i;

  opterr = 0;
  while ((opt = getopt(ac, av, "p:x:y:n:c:t:")) != -1)
    {
      if (opt == '?')
	return (false);
      i = 0;
      while (parse_opt[i].opt)
        {
          if (parse_opt[i].opt == opt)
            {
              if ((parse_opt[i].func)() == false)
                return (false);
              else
                break;
            }
          i++;
        }
    }
  return (true);
}

bool		parse_arg(int ac, char **av)
{
  g_av = av;
  set_default_values();
  if (!check_opts(ac, av))
    return (false);
  return (true);
}
