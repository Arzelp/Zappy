/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun  9 14:40:33 2017 Arthur Josso
** Last update Fri Jun 16 20:52:51 2017 Arthur Josso
*/

#include <stdlib.h>
#include "core.h"

static t_player	*init_player_data(t_team *team)
{
  t_player	*player;

  player = cleaner_malloc(sizeof(t_player));
  player->id = g_player_id++;
  player->team = team;
  player->pos.x = rand() % g_game->map_size.x;
  player->pos.y = rand() % g_game->map_size.y;
  player->dir = rand() % DIR_NBR;
  player->lvl = 1;
  player->tasks = NULL;
  return (player);
}

bool		client_player_init(t_team *team)
{
  t_player	*player;
  int		i;

  if (team->nbr_players == team->max_players)
    {
      send_cmd(CMD_PLAYER_KO);
      g_client->callback = &client_entity_fini;
      return (true);
    }
  player = init_player_data(team);
  i = 0;
  while (team->players[i])
    i++;
  team->players[i] = player;
  team->nbr_players++;
  g_client->type = ENTITY_PLAYER;
  g_client->entity = player;
  g_client->callback = (t_entity_func)&client_player_welcome;
  g_client->callback_dtor = (t_entity_func)&client_player_fini;
  return (true);
}

bool	client_player_welcome(t_player *player)
{
  send_cmd(CMD_PLAYER_NBR_FREE_SLOT,
	   player->team->max_players - player->team->nbr_players);
  send_cmd(CMD_PLAYER_MAP_SIZE, g_game->map_size.x, g_game->map_size.y);
  send_graphics_cmd(CMD_GRAPHIC_NEW_PLAYER, player->id, player->pos.x,
		    player->pos.y, player->dir, player->lvl, player->team->name);
  g_client->callback = (t_entity_func)&client_player_run;
  return (true);
}

bool		client_player_fini(t_player *player)
{
  uint32_t	i;

  //send_cmd(CMD_PLAYER_DEAD);
  task_rm_all(player->tasks);
  i = 0;
  while (i < player->team->nbr_players &&
	 player->team->players[i] != player)
    i++;
  player->team->players[i] = NULL;
  player->team->nbr_players--;
  g_client->callback = &client_entity_fini;
  g_client->callback_dtor = NULL;
  return (true);
}
