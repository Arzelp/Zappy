/*
** queue_get.c for get queue in /client/src/utils/queue/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Tue Jun 27 22:18:20 2017 Frederic Oddou
** Last update Tue Jun 27 23:10:52 2017 Frederic Oddou
*/

#include <stdlib.h>
#include "utils.h"

bool			queue_empty(t_queue *queue)
{
  if (queue->size(queue) > 0)
    return (false);
  return (true);
}

size_t			queue_size(t_queue *queue)
{
  size_t		i;
  t_queue_data		*tmp;

  i = 0;
  if (queue->data == NULL)
    return (0);
  tmp = queue->data;
  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

void			*queue_front(t_queue *queue)
{
  t_queue_data		*tmp;

  if (queue->data == NULL)
    return (NULL);
  if ((tmp = queue->data) != NULL)
    return (tmp->val);
  return (NULL);
}

void			*queue_back(t_queue *queue)
{
  t_queue_data		*tmp;

  if (queue->data == NULL)
    return (NULL);
  tmp = queue->data;
  while (tmp)
    {
      if (tmp->next == NULL)
	return (tmp->val);
      tmp = tmp->next;
    }
  return (NULL);
}
