/*
** trim.c for trim in /client/src/utils/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 21:11:53 2017 Frederic Oddou
** Last update Sat Jun 17 21:23:01 2017 Frederic Oddou
*/

#include <stdlib.h>

char	*trim(char *str)
{
  int	i;
  int	j;

  i = j = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	    i++;
	  if (j > 0 && str[i] != '\0')
	    str[j++] = ' ';
	}
      str[j++] = str[i++];
    }
  str[j] = '\0';
  return (str);
}
