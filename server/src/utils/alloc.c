/*
** misc.c for lol in /home/tetra/rendu/psu/PSU_2016_myftp
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 29 20:45:45 2017 Arthur Josso
** Last update Thu May 25 16:49:58 2017 Arthur Josso
*/

#include <stdlib.h>
#include <string.h>
#include "misc.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    fat_err("malloc");
  memset(ptr, 0, size);
  return (ptr);
}

void	*xrealloc(void *ptr, size_t size)
{
  ptr = realloc(ptr, size);
  if (ptr == NULL)
    fat_err("realloc");
  return (ptr);
}
