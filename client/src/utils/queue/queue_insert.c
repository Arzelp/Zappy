/*
** queue_insert.c for insert queue in /client/src/utils/queue/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Tue Jun 27 22:27:40 2017 Frederic Oddou
** Last update Tue Jun 27 23:09:15 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "utils.h"

void			queue_push(t_queue *queue, void *val)
{
  t_queue_data		*new;

  if (!val || (new = calloc(1, sizeof(*new))) == NULL)
    return ;
  new->val = val;
  if (queue->data)
    new->next = queue->data;
  else
    new->next = NULL;
  queue->data = new;
}

void			queue_emplace(t_queue *queue, void *val)
{
  t_queue_data		*new;
  t_queue_data		*tmp;

  if (!val || (new = calloc(1, sizeof(*new))) == NULL)
    return ;
  new->val = val;
  new->next = NULL;
  if (!queue->data)
    {
      queue->data = new;
      return ;
    }
  tmp = queue->data;
  while (tmp)
    {
      if (tmp->next == NULL)
	{
	  tmp->next = new;
	  return ;
	}
      tmp = tmp->next;
    }
}

void			queue_pop(t_queue *queue)
{
  t_queue_data		*tmp;

  if (!queue->data)
    return ;
  tmp = queue->data;
  queue->data = tmp->next;
  free(tmp);
}
