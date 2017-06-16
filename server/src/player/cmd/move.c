/*
** move.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 20:47:07 2017 Arthur Josso
** Last update Fri Jun 16 20:49:04 2017 Arthur Josso
*/

#include "core.h"

bool    cmd_player_Forward(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_FORWARD, arg);
  return (true);
}
