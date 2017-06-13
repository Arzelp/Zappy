/*
** get_arg.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun 13 13:17:28 2017 Arthur Josso
** Last update Tue Jun 13 15:25:21 2017 Arthur Josso
*/

#include <stdlib.h>
#include <string.h>
#include "core.h"

static int	secured_atoi(const char *arg, int max)
{
  int		nbr;

  if (!is_nbr(arg))
    return (-1);
  nbr = atoi(arg);
  if (max >= 0 && nbr >= max)
    return (-1);
  return (nbr);
}

int	cmd_arg_get_team_id(const char *arg)
{
  if (*arg != '#')
    return (-1);
  arg++;
  if (*arg == '\0')
    return (-1);
  return (secured_atoi(arg, -1));
}

bool		cmd_arg_get_pos(const char *arg, t_pos *pos)
{
  char		buff[8];
  char		*tmp;
  size_t	len;

  tmp = strchr(arg, ' ');
  if (tmp == NULL)
    return (false);
  len = tmp - arg;
  if (len >= 8)
    return (false);
  strncpy(buff, arg, len);
  buff[len] = '\0';
  if ((pos->x = secured_atoi(buff, g_game->map_size.x)) == -1)
    return (false);
  while (*tmp == ' ')
    tmp++;
  if (*tmp == '\0')
    return (false);
  if ((pos->y = secured_atoi(tmp, g_game->map_size.y)) == -1)
    return (false);
  return (true);
}
