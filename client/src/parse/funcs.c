/*
** funcs.c for funcs in /client/src/parse/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 11:00:19 2017 Frederic Oddou
** Last update Sun Jun 18 20:50:48 2017 Frederic Oddou
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "parse.h"
#include "utils.h"

bool		parse_p_opt(t_parse_action action)
{
  int		tmp;

  if (action == PARSE_INIT)
    g_core->port = DFLT_SERVER_PORT;
  else if (action == PARSE_FILL)
    {
      if (!is_nbr(optarg))
	return (false);
      tmp = atoi(optarg);
      if (tmp > USHRT_MAX)
	return (false);
      g_core->port = tmp;
    }
  else if (action == PARSE_CHECK)
    {
      if (g_core->port == 0)
	return (false);
    }
  return (true);
}

bool		parse_n_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    bzero(g_core->name_team, NAME_SIZE);
  else if (action == PARSE_FILL)
    {
      if (!strlen(optarg))
	return (false);
      strncpy(g_core->name_team, optarg, NAME_SIZE);
    }
  else if (action == PARSE_CHECK)
    {
      if (!strlen(g_core->name_team))
	return (false);
    }
  return (true);
}

bool		parse_h_opt(t_parse_action action)
{
  if (action == PARSE_INIT)
    strncpy(g_core->host, DFLT_SERVER_HOST, HOST_SIZE);
  else if (action == PARSE_FILL)
    {
      if (!strlen(optarg))
	return (false);
      strncpy(g_core->host, optarg, HOST_SIZE);
    }
  else if (action == PARSE_CHECK)
    {
      if (!strlen(g_core->host))
	return (false);
    }
  return (true);
}
