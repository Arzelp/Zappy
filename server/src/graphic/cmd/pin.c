/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Tue Jun 13 16:19:12 2017 Arthur Josso
*/

#include "core.h"

bool		cmd_graphic_pin(t_graphic *graphic, const char *arg)
{
  int		player_id;
  t_client	*client;
  t_player	*p;
  uint16_t	*i;

  (void)graphic;
  if ((player_id = cmd_arg_get_team_id(arg)) == -1)
    return (ret_on_bad_arg());
  client = g_server->clients;
  while (client)
    {
      if (client->type == ENTITY_PLAYER &&
	  (int)((t_player*)(client->entity))->id == player_id)
	break;
      client = client->next;
    }
  if (client == NULL)
    return (ret_on_bad_arg());
  p = client->entity;
  i = p->inventory;
  send_cmd(CMD_GRAPHIC_PLAYER_INVENTORY, p->id, p->pos.x, p->pos.y,
	   i[RES_FOOD], i[RES_LINEMATE], i[RES_DERAUMERE], i[RES_SIBUR],
	   i[RES_MENDIANE], i[RES_PHIRAS], i[RES_THYSTAME]);
  return (true);
}
