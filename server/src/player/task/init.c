/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 19:07:49 2017 Arthur Josso
** Last update Fri Jun 23 20:49:59 2017 Arthur Josso
*/

#include "core.h"

static uint8_t	get_nbr_task(t_task *tasks)
{
  uint8_t	nbr;

  nbr = 0;
  while (tasks)
    {
      tasks = tasks->next;
      nbr++;
    }
  return (nbr);
}

void		task_add(t_task **tasks, t_task_type type,
			 const char *arg)
{
  t_task	*new;

  if (get_nbr_task(*tasks) >= MAX_PARALLEL_TASKS)
    return;
   new = cleaner_malloc(sizeof(t_task));
   new->func = task_list[type].func;
   new->exec_time = (task_list[type].duration * 1000) / g_game->frequency;
   new->arg = arg ? cleaner_strcat(NULL, arg) : NULL;
   new->next = *tasks;
   if (*tasks != NULL)
     (*tasks)->prev = new;
   else
     new->exec_time += get_current_time();
   new->prev = NULL;
   *tasks = new;
}

void	task_rm(t_task **tasks, t_task *task)
{
  if (*tasks == task)
    *tasks = task->next;
  if (task->prev)
    task->prev->next = task->next;
  if (task->next)
    task->next->prev = task->prev;
  if (task->arg)
    cleaner_rm_addr(task->arg);
  cleaner_rm_addr(task);
}

void		task_rm_all(t_task **tasks)
{
  t_task	*tmp;
  t_task	*next;

  tmp = *tasks;
  while (tmp)
    {
      next = tmp->next;
      task_rm(tasks, tmp);
      tmp = next;
    }
}
