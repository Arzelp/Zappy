/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 20:33:49 2017 Arthur Josso
** Last update Fri Jun 23 19:49:47 2017 Arthur Josso
*/

#include "core.h"

void		task_run(t_task **tasks)
{
  t_task	*task;
  t_task	*tmp;
  t_time	now;

  task = *tasks;
  while (task && task->next)
    task = task->next;
  if (task == NULL)
    return;
  now = task_get_current_time();
  if (now < task->exec_time)
    return;
  task->func(g_client->entity, task->arg);
  tmp = task;
  task = task->prev;
  task_rm(tasks, tmp);
  if (task != NULL)
    task->exec_time += now;
}
