/*
** queue_class.c for class queue in /client/src/utils/queue/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Tue Jun 27 22:10:38 2017 Frederic Oddou
** Last update Tue Jun 27 23:11:09 2017 Frederic Oddou
*/

#include <stdlib.h>
#include <string.h>
#include "utils.h"

bool			queue_construct(t_queue *queue)
{
  bzero(queue, sizeof(*queue));
  queue->data = NULL;
  queue->empty = &queue_empty;
  queue->size = &queue_size;
  queue->front = &queue_front;
  queue->back = &queue_back;
  queue->push = &queue_push;
  queue->emplace = &queue_emplace;
  queue->pop = &queue_pop;
  queue->construct = &queue_construct;
  queue->destruct = &queue_destruct;
  return (true);
}

void			queue_destruct(t_queue *queue)
{
  while (!queue->empty(queue))
    queue->pop(queue);
}
