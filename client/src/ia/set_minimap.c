/*
** set_minimap.c for minimp in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Wed Jun 21 17:52:21 2017 Paskal Arzel
** Last update Mon Jun 26 14:57:20 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
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
	    return (pow(10, g_elem[i].id));
    i++;
  }
  return (0);
}

static int		calc_value(char *str)
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

static void	complete_minimap(int **minimap)
{
  int		i;
  int		j;
  int		k;
  int		max;

  i = 0;
  k = (g_core->player.level + 1) * (g_core->player.level + 1) - 1;
  max = g_core->player.level * 2 + 1;
  while (i <= g_core->player.level)
  {
    j = i;
    while (j < max && k >= 0)
    {
	    minimap[i][j] = calc_value(g_core->player.view[k]);
      j++;
      k--;
    }
    max--;
    i++;
  }
}

int		**set_minimap(void)
{
  int		**minimap;
  int		i;
  int		j;

  if ((minimap = malloc((g_core->player.level + 2) * sizeof(int *))) == NULL)
    return (NULL);
  i = 0;
  while (i <= g_core->player.level)
  {
    if ((minimap[i] = malloc((g_core->player.level * 2 + 2) * sizeof(int))) == NULL)
			return (NULL);
    j = 0;
    while (j <= g_core->player.level * 2 + 1)
    {
      minimap[i][j] = -1;
      j++;
    }
    i++;
  }
  minimap[i] = NULL;
  complete_minimap(minimap);
  return (minimap);
}
