/*
** move.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 19:46:03 2017 Arthur Josso
** Last update Thu Jun 22 23:11:38 2017 Arthur Josso
*/

#include "core.h"

bool	task_fork(t_player *player, char *arg)
{
  t_egg	*egg;

  (void)arg;
  egg = egg_add(player);
  send_cmd(CMD_PLAYER_OK);
  send_graphics_cmd(CMD_GRAPHIC_FORK_DROP,
		    egg->id, player->id,
		    egg->pos.x, egg->pos.y);
  return (true);
}
