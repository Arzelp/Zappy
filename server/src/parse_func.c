/*
** parse_func.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun  7 14:00:35 2017 Arthur Josso
** Last update Wed Jun  7 14:56:01 2017 Arthur Josso
*/

#include <stdlib.h>
#include <unistd.h>
#include "core.h"

bool    parse_p_opt()
{
  int	tmp;

  if (!is_nbr(optarg))
    return (false);
  tmp = atoi(optarg);
  if (tmp > USHRT_MAX)
    return (false);
  g_server->port = tmp;
  return (true);
}

bool    parse_x_opt()
{
  if (!is_nbr(optarg))
    return (false);
  g_game->map_size.x = atoi(optarg);
  if (g_game->map_size.x == 0 ||
      g_game->map_size.x > MAX_MAP_SIZE)
    return (false);
  return (true);
}

bool    parse_y_opt()
{
  if (!is_nbr(optarg))
    return (false);
  g_game->map_size.y = atoi(optarg);
  if (g_game->map_size.y == 0 ||
      g_game->map_size.y > MAX_MAP_SIZE)
    return (false);
  return (true);
}

bool    parse_c_opt()
{
  if (!is_nbr(optarg))
    return (false);
  g_game->max_players = atoi(optarg);
  if (g_game->max_players == 0 ||
      g_game->max_players > MAX_PLAYERS)
    return (false);
  return (true);
}

bool    parse_t_opt()
{
  if (!is_nbr(optarg))
    return (false);
  g_game->frequency = atoi(optarg);
  if (g_game->frequency == 0 ||
      g_game->frequency > MAX_FERQUENCY)
    return (false);
  return (true);
}
