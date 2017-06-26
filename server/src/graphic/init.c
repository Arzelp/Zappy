/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun  9 14:40:33 2017 Arthur Josso
** Last update Thu Jun 22 23:38:05 2017 Arthur Josso
*/

#include "core.h"

static void	list_players()
{
  t_client	*client;
  t_player	*p;

  client = g_server->clients;
  while (client)
    {
      if (client->type == ENTITY_PLAYER)
	{
	  p = client->entity;
	  send_cmd(CMD_GRAPHIC_NEW_PLAYER, p->id, p->pos.x, p->pos.y,
		   p->dir, p->lvl, p->team->name);
	}
      client = client->next;
    }
}

static bool	list_eggs(t_egg *egg)
{
  send_cmd(CMD_GRAPHIC_FORK_DROP,
	   egg->id, egg->layer_id,
	   egg->pos.x, egg->pos.y);
  return (true);
}

bool	client_graphic_welcome(t_graphic *graphic)
{
  (void)graphic;
  send_cmd(CMD_GRAPHIC_MAP_SIZE, g_game->map_size.x,  g_game->map_size.y);
  send_cmd(CMD_GRAPHIC_TIME_REF, g_game->frequency);
  cmd_graphic_mct(graphic, "");
  cmd_graphic_tna(graphic, "");
  list_players();
  egg_for_each(&list_eggs);
  g_client->callback = (t_entity_func)&client_graphic_run;
  return (true);
}

bool	client_graphic_init()
{
  g_client->type = ENTITY_GRAPHIC;
  g_client->entity = cleaner_malloc(sizeof(t_graphic));
  g_client->callback = (t_entity_func)&client_graphic_welcome;
  g_client->callback_dtor = (t_entity_func)&client_graphic_fini;
  return (true);
}

bool	client_graphic_fini(t_graphic *graphic)
{
  (void)graphic;
  g_client->callback = &client_entity_fini;
  g_client->callback_dtor = NULL;
  return (true);
}
