/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 20:33:49 2017 Arthur Josso
** Last update Fri Jun 16 20:58:09 2017 Arthur Josso
*/

#include "core.h"

void		task_run(t_task **tasks)
{
  t_task	*task;
  t_task	*tmp;
  t_time	now;

  task = *tasks;
  now = task_get_current_time();
  while (task)
    {
      if (now >= task->exec_time)
	{
	  task->func(g_client->entity, task->arg);
	  tmp = task;
	  task = task->next;
	  if (*tasks == tmp)
	    *tasks = task;
	  task_rm(tmp);
	}
      else
	task = task->next;
    }
}