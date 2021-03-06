/*
** death.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 23 16:56:54 2017 Arthur Josso
** Last update Fri Jun 30 16:43:59 2017 Arthur Josso
*/

#include <stdio.h>
#include "core.h"

bool	player_consume_food(t_player *player)
{
  char	buff[BUFF_SIZE];

  if (player->inventory[RES_FOOD] <= 0)
    return (false);
  player->inventory[RES_FOOD]--;
  sprintf(buff, "#%d", player->id);
  for_each_graphic(&cmd_graphic_pin, buff);
  player->starve_time = get_current_time()
    + ((STARVE_DURATION * 1000) / g_game->frequency);
  return (true);
}

bool	player_is_dead(t_player *player)
{
  if (player->starve_time != PLAYER_DEAD &&
      get_current_time() >= player->starve_time)
    {
      if (!player_consume_food(player))
	{
	  player->starve_time = PLAYER_DEAD;
	  send_cmd(CMD_PLAYER_DEAD);
	  return (true);
	}
    }
  return (false);
}
