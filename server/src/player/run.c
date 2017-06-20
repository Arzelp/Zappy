/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 21:04:50 2017 Arthur Josso
** Last update Tue Jun 20 13:55:57 2017 Arthur Josso
*/

#include "core.h"

static const t_entity_cmd	cmd_player[] =
  {
    ADD_CMD_FUNC(player, Connect_nbr),
    ADD_CMD_FUNC(player, Forward),
    ADD_CMD_FUNC(player, Left),
    ADD_CMD_FUNC(player, Right),
    ADD_CMD_FUNC(player, Look),
    ADD_CMD_FUNC(player, Inventory),
    ADD_CMD_FUNC(player, Eject),
    ADD_CMD_FUNC(player, Take),
    ADD_CMD_FUNC(player, Set),
    ADD_CMD_FUNC(player, Incantation),
    {NULL, NULL}
  };

bool	client_player_run(t_player *player)
{
  exec_entity_cmd(cmd_player, player, CMD_PLAYER_KO);
  task_run(&player->tasks);
  return (true);
}
