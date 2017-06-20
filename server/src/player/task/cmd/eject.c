/*
** eject.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 19 16:59:10 2017 Arthur Josso
** Last update Tue Jun 20 18:00:26 2017 Arthur Josso
*/

#include "core.h"

static t_player	*act_player;
static bool	is_alone;

static bool	eject_player(t_client *client)
{
  t_player	*other;

  if (client->type != ENTITY_PLAYER || client->entity == act_player)
    return (true);
  other = client->entity;
  if (other->pos.x == act_player->pos.x &&
      other->pos.y == act_player->pos.y)
    {
      if (is_alone)
	{
	  send_graphics_cmd(CMD_GRAPHIC_PUSH, act_player->id);
	  is_alone = false;
	}
      get_relative_pos(act_player, &other->pos, MOVE_FORWARD);
      send_cmd(CMD_PLAYER_EJECT, umod(act_player->dir + 2, DIR_NBR));
      send_graphics_cmd(CMD_GRAPHIC_PLAYER_POS, other->id,
			other->pos.x, other->pos.y, other->dir);
    }
  return (true);
}

bool	task_eject(t_player *player, char *arg)
{
  (void)arg;
  is_alone = true;
  act_player = player;
  client_for_each(&eject_player);
  if (is_alone)
    send_cmd(CMD_PLAYER_KO);
  else
    send_cmd(CMD_PLAYER_OK);
  return (true);
}
