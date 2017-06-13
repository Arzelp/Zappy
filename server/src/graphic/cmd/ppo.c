/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Tue Jun 13 15:54:14 2017 Arthur Josso
*/

#include "core.h"

bool	ret_on_bad_arg()
{
  send_cmd(CMD_GRAPHIC_BAD_ARG);
  return (true);
}

bool		cmd_graphic_ppo(t_graphic *graphic, const char *arg)
{
  int		player_id;
  t_client	*client;
  t_player	*p;

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
  send_cmd(CMD_GRAPHIC_PLAYER_POS, p->id, p->pos.x, p->pos.y, p->dir);
  return (true);
}
