/*
** incantation.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
**
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
**
** Started on  Tue Jun 20 13:11:07 2017 Arthur Josso
** Last update Mon Jun 26 14:04:39 2017 Arthur Josso
*/

#include "core.h"

static t_player			*act_player;

static const t_incantation	incant_tab[] =
  {
    {1, 1, {0, 1, 0, 0, 0, 0, 0}},
    {2, 2, {0, 1, 1, 1, 0, 0, 0}},
    {3, 2, {0, 2, 0, 1, 0, 2, 0}},
    {4, 4, {0, 1, 1, 2, 0, 1, 0}},
    {5, 4, {0, 1, 2, 1, 3, 0, 0}},
    {6, 6, {0, 1, 2, 3, 0, 1, 0}},
    {7, 6, {0, 2, 2, 2, 2, 2, 1}},
  };

static const t_incantation	*get_incant(t_player *player)
{
  if (player->lvl == 8)
    {
      send_cmd(CMD_PLAYER_KO);
      send_graphics_cmd(CMD_GRAPHIC_INCANTATION_END,
			player->pos.x, player->pos.y, 0);
      return (NULL);
    }
  return (incant_tab + player->lvl - 1);
}

static bool	is_enough_ressource(const t_pos *pos, const t_incantation *inc)
{
  t_ressource	res;

  res = RES_FOOD;
  while (res != RES_NBR)
    {
      if (g_game->map[pos->y][pos->x][res] != inc->ressource[res])
	{
	  send_cmd(CMD_PLAYER_KO);
	  send_graphics_cmd(CMD_GRAPHIC_INCANTATION_END, pos->x, pos->y, 0);
	  return (false);
	}
      res++;
    }
  return (true);
}

static bool	is_enough_player(t_player *player, const t_incantation *inc)
{
  t_client	*client;
  t_player	*other;
  int		nbr_player;

  client = g_server->clients;
  nbr_player = 0;
  while (client)
    {
      if (client->type == ENTITY_PLAYER)
	{
	  other = client->entity;
	  if (other->lvl == player->lvl &&
	      other->pos.x == player->pos.x &&
	      other->pos.y == player->pos.y)
	    nbr_player++;
	}
      client = client->next;
    }
  if (nbr_player == inc->nbr_player)
    return (true);
  send_cmd(CMD_PLAYER_KO);
  send_graphics_cmd(CMD_GRAPHIC_INCANTATION_END,
		    player->pos.x, player->pos.y, 0);
  return (false);
}

static bool	launch_incantation(t_client *client)
{
  t_player	*player;

  if (client->type != ENTITY_PLAYER)
    return (true);
  player = client->entity;
  if (act_player->lvl == player->lvl &&
      act_player->pos.x == player->pos.x &&
      act_player->pos.y == player->pos.y)
    {
      player->lvl++;
      send_graphics_cmd(CMD_GRAPHIC_PLAYER_LVL, player->id, player->lvl);
    }
  return (true);
}

bool			task_incantation(t_player *player, char *arg)
{
  const t_incantation	*inc;

  (void)arg;
  if ((inc = get_incant(player)) == NULL)
    return (true);
  if (!is_enough_ressource(&player->pos, inc))
    return (true);
  if (!is_enough_player(player, inc))
    return (true);
  act_player = player;
  send_graphics_cmd(CMD_GRAPHIC_INCANTATION_END,
                    player->pos.x, player->pos.y, 1);
  client_for_each(&launch_incantation);
  send_cmd(CMD_PLAYER_INCANTATION_END, player->lvl);
  for_each_graphic(&cmd_graphic_mct, NULL);
  return (true);
}
