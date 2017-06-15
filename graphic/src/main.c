/*
** main.c for main in /home/paskal/rendu/System_Unix/PSU_2016_zappy/graphic/src/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 15 17:37:16 2017 Paskal Arzel
** Last update Thu Jun 15 17:40:56 2017 Paskal Arzel
*/

#include "graphic.h"

int	main(int ac, char **av)
{
  if (ac == 1 || !strcmp(av[1], "--help"))
    return (help());
  return (EXIT_SUCCESS);
}
