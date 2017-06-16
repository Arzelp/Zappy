/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 19:07:49 2017 Arthur Josso
** Last update Fri Jun 16 20:59:44 2017 Arthur Josso
*/

#include "core.h"

void		task_add(t_task **tasks, t_task_type type,
			 const char *arg)
{
  t_task	*new;

   new = cleaner_malloc(sizeof(t_task));
   new->func = task_list[type].func;
   new->exec_time = task_get_current_time()
     + ((task_list[type].duration * 1000) / g_game->frequency);
   new->arg = arg ? cleaner_strcat(NULL, arg) : NULL;
   new->next = *tasks;
   if (*tasks != NULL)
     (*tasks)->prev = new;
   new->prev = NULL;
   *tasks = new;
}

void	task_rm(t_task *task)
{
  if (task->prev)
    task->prev->next = task->next;
  if (task->next)
    task->next->prev = task->prev;
  if (task->arg)
    cleaner_rm_addr(task->arg);
  cleaner_rm_addr(task);
}

void		task_rm_all(t_task *task)
{
  t_task	*next;

  while (task)
    {
      next = task->next;
      task_rm(task);
      task = next;
    }
}
