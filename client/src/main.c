/*
** main.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jun  6 13:55:14 2017 Arthur Josso
** Last update Tue Jun 13 17:15:12 2017 Paskal Arzel
*/

#include "core.h"

int	main(int ac, char **av)
{
  t_client	client;

  if (ac == 1 || !strcmp(av[1], "--help"))
    return (help());
  return (0);
}
