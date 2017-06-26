/*
** team.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun 15 13:51:31 2017 Arthur Josso
** Last update Mon Jun 26 16:08:50 2017 Arthur Josso
*/

#include <unistd.h>
#include <string.h>
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
  while (g_av[i] && g_av[i] != optarg)
    i++;
  return (g_av + i);
}

static bool	name_collision()
{
  int		i;
  int		j;

  i = 0;
  while (g_game->team[i])
    {
      j = 0;
      while (g_game->team[j])
	{
	  if (i != j && strcmp(g_game->team[i]->name,
			       g_game->team[j]->name) == 0)
	    return (true);
	  j++;
	}
      i++;
    }
  return (false);
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
      if ((start = get_team_start()) == NULL)
	return (false);
      nbr_team = get_nbr_team(start);
      g_game->team = cleaner_malloc((nbr_team + 1) * sizeof(t_team*));
      i = -1;
      while (++i < nbr_team)
	{
	  g_game->team[i] = cleaner_malloc(sizeof(t_team));
	  g_game->team[i]->name = start[i];
	}
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->team == NULL || g_game->team[0] == NULL || name_collision())
        return (false);
    }
  return (true);
}
