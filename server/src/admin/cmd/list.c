/*
** test.c for lo in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun 28 17:35:38 2017 Arthur Josso
** Last update Wed Jun 28 18:27:44 2017 Arthur Josso
*/

#include "core.h"

static bool	describe_player(t_player *player)
{
  uint16_t	*i;

  i = player->inventory;
  send_cmd(CMD_ADMIN_LIST, player->id, player->pos.x, player->pos.y,
	   player->dir, player->lvl, i[RES_FOOD], i[RES_LINEMATE],
	   i[RES_DERAUMERE], i[RES_SIBUR], i[RES_MENDIANE],
	   i[RES_PHIRAS], i[RES_THYSTAME]);
  return (true);
}

bool    cmd_admin_list(t_admin *admin, const char *arg)
{
  (void)admin;
  (void)arg;
  player_for_each(false, &describe_player);
  return (true);
}
