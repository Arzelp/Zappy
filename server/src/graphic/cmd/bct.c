/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Tue Jun 13 15:54:03 2017 Arthur Josso
*/

#include "core.h"

bool		cmd_graphic_bct(t_graphic *graphic, const char *arg)
{
  t_pos		pos;
  uint16_t	*t;

  (void)graphic;
  if (!cmd_arg_get_pos(arg, &pos))
    return (ret_on_bad_arg());
  t = g_game->map[pos.y][pos.x];
  send_cmd(CMD_GRAPHIC_TILE_CONTENT, pos.x, pos.y, t[RES_FOOD],
	   t[RES_LINEMATE], t[RES_DERAUMERE], t[RES_SIBUR],
	   t[RES_MENDIANE], t[RES_PHIRAS], t[RES_THYSTAME]);
  return (true);
}
