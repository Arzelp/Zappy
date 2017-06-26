/*
** win.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 23 20:15:14 2017 Arthur Josso
** Last update Fri Jun 23 20:28:36 2017 Arthur Josso
*/

#include <stdio.h>
#include "core.h"

static bool	reset_nbr_op_players(t_client *client)
{
  t_player	*player;

  if (client->type != ENTITY_PLAYER)
    return (true);
  player = client->entity;
  if (player->lvl >= MAX_PLAYER_LVL)
    player->team->nbr_op_players++;
  return (true);
}

bool	is_there_a_winner()
{
  int	i;

  i = 0;
  while (g_game->team[i])
    g_game->team[i++]->nbr_op_players = 0;
  client_for_each(&reset_nbr_op_players);
  i = 0;
  while	(g_game->team[i])
    {
      if (g_game->team[i]->nbr_op_players >= NBR_OP_PLAYERS_TO_WIN)
	{
	  fprintf(stderr, "Team \"%s\" wins the game\n", g_game->team[i]->name);
	  send_graphics_cmd(CMD_GRAPHIC_END, g_game->team[i]->name);
	  return (true);
	}
      i++;
    }
  return (false);
}
