/*
** parse_func.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun  7 14:00:35 2017 Arthur Josso
** Last update Wed Jun  7 15:50:07 2017 Arthur Josso
*/

#include <stdlib.h>
#include <unistd.h>
#include "core.h"

bool    parse_p_opt(t_parse_action action)
{
  int	tmp;

  if (action == PARSE_INIT)
    g_server->port = 0;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      tmp = atoi(optarg);
      if (tmp > USHRT_MAX)
	return (false);
      g_server->port = tmp;
    }
  else if (action == PARSE_CHECK)
    {
      if (g_server->port == 0)
	return (false);
    }
  return (true);
}

bool    parse_x_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    g_game->map_size.x = -1;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      g_game->map_size.x = atoi(optarg);
      if (g_game->map_size.x == 0 ||
	  g_game->map_size.x > MAX_MAP_SIZE)
	return (false);
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->map_size.x == -1)
        return (false);
    }
  return (true);
}

bool    parse_y_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    g_game->map_size.y = -1;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      g_game->map_size.y = atoi(optarg);
      if (g_game->map_size.y == 0 ||
	  g_game->map_size.y > MAX_MAP_SIZE)
	return (false);
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->map_size.x == -1)
        return (false);
    }
  return (true);
}

bool    parse_c_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    g_game->max_players = -1;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      g_game->max_players = atoi(optarg);
      if (g_game->max_players == 0 ||
	  g_game->max_players > MAX_PLAYERS)
	return (false);
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->max_players == (uint32_t)-1)
        return (false);
    }
  return (true);
}

bool    parse_t_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    g_game->frequency = -1;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      g_game->frequency = atoi(optarg);
      if (g_game->frequency == 0 ||
	  g_game->frequency > MAX_FERQUENCY)
	return (false);
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->frequency == (uint32_t)-1)
        return (false);
    }
  return (true);
}
