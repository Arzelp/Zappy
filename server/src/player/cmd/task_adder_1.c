/*
** move.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 20:47:07 2017 Arthur Josso
** Last update Mon Jun 19 19:37:14 2017 Arthur Josso
*/

#include "core.h"

bool    cmd_player_Look(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_LOOK, arg);
  return (true);
}

bool	cmd_player_Inventory(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_INVENTORY, arg);
  return (true);
}

bool	cmd_player_Eject(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_EJECT, arg);
  return (true);
}

bool	cmd_player_Take(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_TAKE, arg);
  return (true);
}

bool	cmd_player_Set(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_SET, arg);
  return (true);
}
