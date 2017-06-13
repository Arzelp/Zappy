/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun  9 14:40:33 2017 Arthur Josso
** Last update Tue Jun 13 11:59:02 2017 Arthur Josso
*/

#include <stdlib.h>
#include "core.h"

bool		client_player_init(t_team *team)
{
  t_player	*player;
  int		i;

  if (team->nbr_players == g_game->max_players)
    {
      send_cmd(CMD_PLAYER_KO);
      g_client->callback = &client_entity_fini;
      return (true);
    }
  player = cleaner_malloc(sizeof(t_player));
  player->id = g_player_id++;
  player->team = team;
  player->pos.x = rand() % g_game->map_size.x;
  player->pos.y	= rand() % g_game->map_size.y;
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
	   g_game->max_players - player->team->nbr_players);
  send_cmd(CMD_PLAYER_MAP_SIZE, g_game->map_size.x, g_game->map_size.y);
  g_client->callback = (t_entity_func)&client_player_run;
  return (true);
}

bool		client_player_fini(t_player *player)
{
  uint32_t	i;

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
