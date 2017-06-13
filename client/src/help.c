/*
** help.c for help in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 13 17:14:14 2017 Paskal Arzel
** Last update Tue Jun 13 17:16:17 2017 Paskal Arzel
*/

#include "core.h"

int	help(void)
{
  printf("USAGE: ./client -p port -n name -h machine\n\
	 port is the port number\n\
	 name is the name of the team\n\
	 machine is the name of the machine; localhost by default\n");
  return (EXIT_SUCCESS);
}
