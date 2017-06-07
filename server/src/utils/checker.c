/*
** checker.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun  7 14:02:18 2017 Arthur Josso
** Last update Wed Jun  7 14:06:55 2017 Arthur Josso
*/

#include <ctype.h>
#include <stdbool.h>

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
