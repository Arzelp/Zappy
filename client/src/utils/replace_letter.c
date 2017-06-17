/*
** replace_letter.c for replace letter in /client/src/utils/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 21:23:56 2017 Frederic Oddou
** Last update Sat Jun 17 21:25:44 2017 Frederic Oddou
*/

#include <stdlib.h>

char		*replace_letter(char *str, char find, char replace)
{
  size_t	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i])
    {
      if (str[i] == find)
	str[i] = replace;
      i++;
    }
  return (str);
}
