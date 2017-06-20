/*
** task_adder_2.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun 20 13:54:50 2017 Arthur Josso
** Last update Tue Jun 20 13:55:29 2017 Arthur Josso
*/

#include "core.h"

bool    cmd_player_Incantation(t_player *player, const char *arg)
{
  send_cmd(CMD_PLAYER_INCANTATION_START);
  task_add(&player->tasks, TASK_INCANTATION, arg);
  return (true);
}
