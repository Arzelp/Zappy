/*
** case_analysis.c for case_analysis in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 16:22:02 2017 Paskal Arzel
** Last update Thu Jun 29 16:27:46 2017 Paskal Arzel
*/

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"

static char		*get_next_word(char *ptr)
{
  int	i;
  bool space;

  i = 0;
  space = false;
  while (ptr[i])
  {
    if (ptr[i] == ' ' || ptr[i] == '\t')
			space = true;
    if (ptr[i] != ' ' && ptr[i] != '\t' && space)
			return (ptr + i);
    i++;
  }
  return (NULL);
}

static int		get_value(char *ptr)
{
  int i;

  i = 0;
  while (g_elem[i].id != -1)
  {
    if (!strncasecmp(ptr, g_elem[i].name, strlen(g_elem[i].name)))
	    return (pow(10, g_elem[i].id - 1));
    i++;
  }
  return (0);
}

int		calc_value(char *str)
{
  int		res;
  char	*ptr;

  if (str == NULL)
    return (-1);
  res = 0;
  ptr = str;
  while (ptr[0] != '\0')
  {
    res += get_value(ptr);
    if ((ptr = get_next_word(ptr)) == NULL)
			return (res);
  }
  return (res);
}

static bool	is_player(char *ptr)
{
  if (!strncasecmp(ptr, "player", strlen("player")))
    return (true);
  return (0);
}

int count_player(char *str)
{
  int		res;
  char	*ptr;

  if (str == NULL)
    return (-1);
  res = 0;
  ptr = str;
  while (ptr[0] != '\0')
  {
    res += is_player(ptr);
    if ((ptr = get_next_word(ptr)) == NULL)
			return (res);
  }
  return (res);
}
