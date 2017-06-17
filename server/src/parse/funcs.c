/*
** parse_func.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun  7 14:00:35 2017 Arthur Josso
** Last update Sat Jun 17 14:27:46 2017 Arthur Josso
*/

#include <stdlib.h>
#include <unistd.h>
#include "core.h"

bool    parse_p_opt(t_parse_action action)
{
  int	tmp;

  if (action == PARSE_INIT)
    g_server->port = DFLT_SERVER_PORT;
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
    g_game->map_size.x = DFLT_MAP_SIZE_X;
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
      if (g_game->map_size.x == (uint32_t)-1)
        return (false);
    }
  return (true);
}

bool    parse_y_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    g_game->map_size.y = DFLT_MAP_SIZE_Y;
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
      if (g_game->map_size.y == (uint32_t)-1)
        return (false);
    }
  return (true);
}

bool    parse_c_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    g_game->max_players_init = DFLT_MAX_PLAYERS;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      g_game->max_players_init = atoi(optarg);
      if (g_game->max_players_init == 0 ||
	  g_game->max_players_init > MAX_PLAYERS)
	return (false);
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->max_players_init == (uint32_t)-1)
        return (false);
    }
  return (true);
}

bool    parse_f_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    g_game->frequency = DFLT_FREQUENCY;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      g_game->frequency = atoi(optarg);
      if (g_game->frequency == 0 ||
	  g_game->frequency > MAX_FREQUENCY)
	return (false);
    }
  else if (action == PARSE_CHECK)
    {
      if (g_game->frequency == (uint32_t)-1)
        return (false);
    }
  return (true);
}
