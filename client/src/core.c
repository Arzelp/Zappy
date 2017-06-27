/*
** core.c for core in /client/src/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Tue Jun 27 23:16:29 2017 Frederic Oddou
** Last update Tue Jun 27 23:21:22 2017 Frederic Oddou
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "core.h"

void		core_init(t_core *core)
{
  bzero(core, sizeof(*core));
  g_core = core;
  queue_construct(&g_core->queue);
}

void		core_destruct()
{
  g_core->queue.destruct(&g_core->queue);
  close_socket();
}

void		core_usage(const char *name)
{
  fprintf(stderr, "USAGE: %s -p port -n name -h machine\n", name);
  fprintf(stderr, "\tport\tis the port number\n");
  fprintf(stderr, "\tname\tis the name of the team\n");
  fprintf(stderr, "\tmachine\tis the name of the machine; "
	  "localhost by default\n");
}
