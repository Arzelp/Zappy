/*
** move.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 19:46:03 2017 Arthur Josso
** Last update Fri Jun 16 20:53:50 2017 Arthur Josso
*/

#include "core.h"

bool	task_forward(t_player *player, char *arg)
{
  send_cmd(CMD_PLAYER_OK);
  return (true);
}
