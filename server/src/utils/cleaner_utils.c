/*
** cleaner_utils.c for lol in /home/tetra/rendu/psu/PSU_2016_myirc
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed May 24 18:41:12 2017 Arthur Josso
** Last update Tue Jun  6 15:45:31 2017 Arthur Josso
*/

#include <string.h>
#include "cleaner.h"
#include "misc.h"

char	*cleaner_strcat(char *dest, const char *src)
{
  char	*tmp;

  tmp = xmalloc((dest ? strlen(dest) : 0) + strlen(src) + 1);
  cleaner_add_addr(tmp);
  if (dest)
    {
      strcat(tmp, dest);
      cleaner_rm_addr(dest);
    }
  strcat(tmp, src);
  return (tmp);
}

void	*cleaner_malloc(size_t size)
{
  void	*ptr;

  ptr = xmalloc(size);
  cleaner_add_addr(ptr);
  return (ptr);
}

void		*cleaner_realloc(void *ptr, size_t size)
{
  void		*tmp;
  size_t	i;

  if (size == 0)
    {
      cleaner_rm_addr(ptr);
      return (NULL);
    }
  else if (ptr == NULL)
    return (cleaner_malloc(size));
  tmp = xrealloc(ptr, size);
  if (tmp != ptr)
    {
      i = 0;
      while (i < nbr_addrs)
	{
	  if (addrs[i] == ptr)
	    addrs[i] = tmp;
	  i++;
	}
    }
  return (tmp);
}

void	*cleaner_resize_container(void *ptr, size_t *max, size_t size)
{
  if (*max == 0)
    {
      *max = 1;
      return (xmalloc((*max) * size));
    }
  *max *= 2;
  return (xrealloc(ptr, (*max) * size));
}
