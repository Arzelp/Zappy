/*
** core.h for core in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/inc/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 13 17:11:24 2017 Paskal Arzel
** Last update Tue Jun 13 17:57:51 2017 Paskal Arzel
*/

#ifndef CORE_H__
#define CORE_H__

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

typedef struct s_conn
{
  int		port;
  char	*mach;
}t_conn;

typedef struct s_client
{
  t_conn	infos;
}t_client;

int	help(void);

#endif
