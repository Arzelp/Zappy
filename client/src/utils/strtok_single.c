/*
** strtok_single.c for single strtok in /client/src/utils/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 20:03:35 2017 Frederic Oddou
** Last update Sat Jun 17 20:05:24 2017 Frederic Oddou
*/

#include <string.h>

char		*strtok_single(char *str, char const *delims)
{
  static char	*src = NULL;
  char		*p;
  char		*ret;

  ret = 0;
  if (str != NULL)
    src = str;
  if (src == NULL)
    return (NULL);
  if ((p = strpbrk(src, delims)) != NULL)
    {
      *p  = 0;
      ret = src;
      src = ++p;
    }
  else if (*src)
    {
      ret = src;
      src = NULL;
    }
  return (ret);
}
