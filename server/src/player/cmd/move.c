/*
** move.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 20:47:07 2017 Arthur Josso
** Last update Sat Jun 17 14:06:47 2017 Arthur Josso
*/

#include "core.h"

bool    cmd_player_Forward(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_FORWARD, arg);
  return (true);
}

bool    cmd_player_Left(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_LEFT, arg);
  return (true);
}

bool	cmd_player_Right(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_RIGHT, arg);
  return (true);
}
