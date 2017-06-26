/*
** nbr_slot.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 18:53:48 2017 Arthur Josso
** Last update Thu Jun 22 23:31:34 2017 Arthur Josso
*/

#include "core.h"

bool    cmd_player_Connect_nbr(t_player *player, const char *arg)
{
  int	nbr_slot;

  (void)arg;
  nbr_slot = player->team->max_players - player->team->nbr_players;
  if (nbr_slot < 0)
    nbr_slot = 0;
  send_cmd(CMD_PLAYER_NBR_FREE_SLOT, nbr_slot);
  return (true);
}
