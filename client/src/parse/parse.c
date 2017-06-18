/*
** parse.c for parse in /client/src/parse/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 10:34:50 2017 Frederic Oddou
** Last update Sun Jun 18 20:50:54 2017 Frederic Oddou
*/

#include <unistd.h>
#include "core.h"
#include "parse.h"

static const t_parse_opt g_parse_opt[] =
  {
    {'p', &parse_p_opt},
    {'n', &parse_n_opt},
    {'h', &parse_h_opt},
    {'\0', NULL}
  };

static bool	for_each_parse_func(t_parse_action action, char opt)
{
  int		i;

  i = 0;
  while (g_parse_opt[i].opt)
    {
      if (opt == -1 || g_parse_opt[i].opt == opt)
	{
	  if ((g_parse_opt[i].func)(action) == false)
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
  while ((opt = getopt(ac, av, "p:n:h:")) != -1)
    {
      if (opt == '?')
	return (false);
      if (!for_each_parse_func(PARSE_FILL, opt))
  	return (false);
    }
  return (true);
}

bool		parse(int ac, char **av)
{
  if (!for_each_parse_func(PARSE_INIT, -1))
    return (false);
  if (!check_opts(ac, av))
    return (false);
  if (!for_each_parse_func(PARSE_CHECK, -1))
    return (false);
  return (true);
}
