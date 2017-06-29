/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 21:04:50 2017 Arthur Josso
** Last update Wed Jun 28 18:29:10 2017 Arthur Josso
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
    ADD_CMD_FUNC(player, Broadcast),
    ADD_CMD_FUNC(player, Fork),
    {NULL, NULL}
  };

bool	client_player_run(t_player *player)
{
  exec_entity_cmd(cmd_player, player, CMD_PLAYER_KO);
  task_run(&player->tasks);
  return (true);
}

void		player_for_each(bool set_current, t_player_callback callback)
{
  t_client	*client;
  t_client	*tmp;
  t_client	*save;

  save = g_client;
  client = g_server->clients;
  while (client)
    {
      tmp = client->next;
      if (set_current)
	g_client = client;
      if (client->type == ENTITY_PLAYER &&
	  callback(client->entity) == false)
        client_rm(client);
      client = tmp;
    }
  g_client = save;
}
