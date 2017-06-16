/*
** time.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 20:20:58 2017 Arthur Josso
** Last update Fri Jun 16 20:57:50 2017 Arthur Josso
*/

#include <time.h>
#include "task.h"

t_time			task_get_current_time()
{
  struct timespec	spec;
  t_time		time;

  clock_gettime(CLOCK_REALTIME, &spec);
  time = spec.tv_sec * 1000;
  time += spec.tv_nsec / 1e6;
  return (time);
}
