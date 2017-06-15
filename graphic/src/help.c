/*
** help.c for help in /home/paskal/rendu/System_Unix/PSU_2016_zappy/graphic/src/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 15 17:39:38 2017 Paskal Arzel
** Last update Thu Jun 15 17:40:05 2017 Paskal Arzel
*/

#include "graphic.h"

int	help(void)
{
  printf("USAGE: ./client -p port -n name -h machine\n\
	 port is the port number\n\
	 name is the name of the team\n\
	 machine is the name of the machine; localhost by default\n");
  return (EXIT_SUCCESS);
}
