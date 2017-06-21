/*
** inventory.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 19 16:12:04 2017 Arthur Josso
** Last update Mon Jun 19 20:05:53 2017 Arthur Josso
*/

#include <stdio.h>
#include <string.h>
#include "core.h"

static void	warn_graphic_clients(t_cmd_type type, t_player *p,
				     t_ressource ressource)
{
  uint16_t	*i;

  send_graphics_cmd(type, p->id, ressource);
  i = p->inventory;
  send_graphics_cmd(CMD_GRAPHIC_PLAYER_INVENTORY, p->id, p->pos.x, p->pos.y,
		    i[RES_FOOD], i[RES_LINEMATE], i[RES_DERAUMERE], i[RES_SIBUR],
		    i[RES_MENDIANE], i[RES_PHIRAS], i[RES_THYSTAME]);
  i = g_game->map[p->pos.y][p->pos.x];
  send_graphics_cmd(CMD_GRAPHIC_TILE_CONTENT, p->pos.x, p->pos.y, i[RES_FOOD],
		    i[RES_LINEMATE], i[RES_DERAUMERE], i[RES_SIBUR],
		    i[RES_MENDIANE], i[RES_PHIRAS], i[RES_THYSTAME]);
}

static t_ressource	parse_ressource(char *res)
{
  t_ressource		ressource;

  if (res == NULL)
    return (RES_NONE);
  ressource = RES_FOOD;
  while (ressource != RES_NBR)
    {
      if (strcasecmp(g_ressources[ressource] + 1, res) == 0)
	return (ressource);
      ressource++;
    }
  return (RES_NONE);
}

bool		task_take(t_player *player, char *arg)
{
  t_ressource	ressource;

  ressource = parse_ressource(arg);
  if (ressource == RES_NONE)
    send_cmd(CMD_PLAYER_KO);
  else if (g_game->map[player->pos.y][player->pos.x][ressource] == 0)
    send_cmd(CMD_PLAYER_KO);
  else
    {
      g_game->map[player->pos.y][player->pos.x][ressource]--;
      player->inventory[ressource]++;
      send_cmd(CMD_PLAYER_OK);
      warn_graphic_clients(CMD_GRAPHIC_TAKE, player, ressource);
    }
  return (true);
}

bool		task_set(t_player *player, char *arg)
{
  t_ressource	ressource;

  ressource = parse_ressource(arg);
  if (ressource == RES_NONE)
    send_cmd(CMD_PLAYER_KO);
  else if (player->inventory[ressource] == 0)
    send_cmd(CMD_PLAYER_KO);
  else
    {
      player->inventory[ressource]--;
      g_game->map[player->pos.y][player->pos.x][ressource]++;
      send_cmd(CMD_PLAYER_OK);
      warn_graphic_clients(CMD_GRAPHIC_DROP, player, ressource);
    }
  return (true);
}
