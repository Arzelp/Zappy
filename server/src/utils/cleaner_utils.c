/*
** cleaner_utils.c for lol in /home/tetra/rendu/psu/PSU_2016_myirc
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed May 24 18:41:12 2017 Arthur Josso
** Last update Mon Jun 26 18:52:36 2017 Arthur Josso
*/

#include <string.h>
#include "cleaner.h"
#include "misc.h"

char	*cleaner_strcat(char *dest, const char *src)
{
  if (dest == NULL)
    {
      dest = xmalloc(strlen(src) + 1);
      cleaner_add_addr(dest);
      strcpy(dest, src);
    }
  else
    {
      dest = cleaner_realloc(dest, strlen(dest) + strlen(src) + 1);
      strcat(dest, src);
    }
  return (dest);
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
