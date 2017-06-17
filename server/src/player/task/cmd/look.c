/*
** look.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Jun 17 19:41:53 2017 Arthur Josso
** Last update Sat Jun 17 21:02:38 2017 Arthur Josso
*/

#include <string.h>
#include "core.h"

static int	nbr_players_on_tile;
static t_pos	tile_pos;

static bool	callback_count_players_on_tile(t_client *client)
{
  t_player	*player;

  if (client->type == ENTITY_PLAYER)
    {
      player = client->entity;
      if (player->pos.x == tile_pos.x &&
	  player->pos.y == tile_pos.y)
	nbr_players_on_tile++;
    }
  return (true);
}

static void	add_tile_content_to_buff(char **buff)
{
  t_ressource	ressource;
  uint16_t	nbr_res;

  nbr_players_on_tile = 0;
  client_for_each(&callback_count_players_on_tile);
  while (nbr_players_on_tile-- != 0)
    *buff = cleaner_strcat(*buff, " player");
  ressource = RES_FOOD;
  while (ressource != RES_NBR)
    {
      nbr_res = g_game->map[tile_pos.y][tile_pos.x][ressource];
      while (nbr_res-- != 0)
	*buff = cleaner_strcat(*buff, g_ressources[ressource]);
      ressource++;
    }
  *buff = cleaner_strcat(*buff, ",");
}

static void	for_each_lookable_tile(t_player *player, char **buff)
{
  uint8_t	line;
  int8_t	nbr_ret;
  int8_t	nbr_run;

  tile_pos = player->pos;
  line = 0;
  while (line <= player->lvl)
    {
      nbr_run = line * 2 + 1;
      nbr_ret = nbr_run - 2;
      if (nbr_ret > 0)
	get_relative_pos(player, &tile_pos, MOVE_FORWARD);
      while (nbr_ret-- > 0)
	get_relative_pos(player, &tile_pos, MOVE_LEFT);
      while (nbr_run-- > 0)
	{
	  add_tile_content_to_buff(buff);
	  if (nbr_run > 0)
	    get_relative_pos(player, &tile_pos, MOVE_RIGHT);
	}
      line++;
    }
}

bool	task_look(t_player *player, char *arg)
{
  char	*buff;
  char	*tmp;

  (void)arg;
  buff = cleaner_strcat(NULL, "[");
  for_each_lookable_tile(player, &buff);
  tmp = strrchr(buff, ',');
  *tmp = '\0';
  buff = cleaner_strcat(buff, " ]\n");
  g_client->obuff = cleaner_strcat(g_client->obuff, buff);
  cleaner_rm_addr(buff);
  return (true);
}
