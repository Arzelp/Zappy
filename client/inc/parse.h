/*
** parse.h for parse in /client/inc/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sun Jun 18 20:49:51 2017 Frederic Oddou
** Last update Sun Jun 18 20:50:32 2017 Frederic Oddou
*/

#pragma once

#include <stdbool.h>

/*
** @parse
** Parse all arguments given in parameters.
*/

typedef enum
{
  PARSE_INIT,
  PARSE_FILL,
  PARSE_CHECK
}		t_parse_action;

typedef struct
{
  char		opt;
  bool 		(*func)(t_parse_action action);
}		t_parse_opt;

bool		parse(int ac, char **av);
bool		parse_p_opt(t_parse_action action);
bool		parse_n_opt(t_parse_action action);
bool		parse_h_opt(t_parse_action action);
