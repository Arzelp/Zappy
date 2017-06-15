/*
** team.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun 15 13:51:31 2017 Arthur Josso
** Last update Thu Jun 15 16:22:45 2017 Arthur Josso
*/

#include <unistd.h>
#include "core.h"

static char **g_av;

void	parse_team_set_av(char **av)
{
  g_av = av;
}

static int	get_nbr_team(char **start)
{
  int		nbr;

  nbr = 0;
  while (start[nbr] &&
	 start[nbr][0] != '-' &&
	 start[nbr][0] != '\0')
    nbr++;
  return (nbr);
}

static char	**get_team_start()
{
  int		i;

  i = 0;
  while (g_av[i] != optarg)
    i++;
  return (g_av + i);
}

bool    parse_n_opt(t_parse_action action)
{
  char	**start;
  int	nbr_team;
  int	i;

  if (action == PARSE_INIT)
    g_game->team = NULL;
  else if (action == PARSE_FILL)
    {
      start = get_team_start();
      nbr_team = get_nbr_team(start);
      g_game->team = cleaner_malloc((nbr_team + 1) * sizeof(t_team*));
      i = 0;
      while (i < nbr_team)
	{
	  g_game->team[i] = cleaner_malloc(sizeof(t_team));
	  g_game->team[i]->name = start[i];
	  i++;
	}
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->team == NULL || g_game->team[0] == NULL)
        return (false);
    }
  return (true);
}
