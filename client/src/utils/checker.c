/*
** checker.c for lol in /client/src/utils/
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Wed Jun  7 14:02:18 2017 Arthur Josso
** Last update Fri Jun 16 14:23:08 2017 Frederic Oddou
*/

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool	is_nbr(const char *s)
{
  while (*s)
    {
      if (!isdigit(*s))
	return (false);
      s++;
    }
  return (true);
}

bool	is_answer_ok(const char *s)
{
  if (!strcmp(s, "ok"))
    return (true);
  return (false);
}
