/*
** list.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server/src/player/task
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 19:35:56 2017 Arthur Josso
** Last update Tue Jun 20 17:32:23 2017 Arthur Josso
*/

#include "task.h"

const t_task_list	task_list[] =
  {
    {&task_forward, 7},
    {&task_left, 7},
    {&task_right, 7},
    {&task_look, 7},
    {&task_inventory, 1},
    {&task_eject, 7},
    {&task_take, 7},
    {&task_set, 7},
    {&task_incantation, 300},
    {&task_broadcast, 7},
    {NULL, 0}
  };
