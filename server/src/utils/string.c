/*
** string.c for lol in /home/tetra/rendu/psu/PSU_2016_myirc
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu May 25 16:51:27 2017 Arthur Josso
** Last update Fri May 26 17:41:45 2017 Arthur Josso
*/

#include <string.h>

void	strmove(char *dest, const char *src)
{
  memmove(dest, src, strlen(src) + 1);
}

void	strcapitalize(char *s)
{
  while (*s)
    {
      if (*s >= 'a' && *s <= 'z')
	*s -= 'a' - 'A';
      s++;
    }
}
