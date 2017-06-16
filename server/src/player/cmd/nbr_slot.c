/*
** nbr_slot.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 18:53:48 2017 Arthur Josso
** Last update Fri Jun 16 18:57:15 2017 Arthur Josso
*/

#include "core.h"

bool    cmd_player_Connect_nbr(t_player *player, const char *arg)
{
  (void)arg;
  send_cmd(CMD_PLAYER_NBR_FREE_SLOT,
	   player->team->max_players - player->team->nbr_players);
  return (true);
}
