/*
** hash.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun 28 17:44:34 2017 Arthur Josso
** Last update Wed Jun 28 17:57:39 2017 Arthur Josso
*/

#include <stdint.h>

uint32_t	hash_djb2(const char *str)
{
  uint32_t hash;

  hash = 5381;
  while (*str)
    {
      hash = ((hash << 5) + hash) + *str;
      str++;
    }
  return (hash);
}
