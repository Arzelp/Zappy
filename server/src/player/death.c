/*
** death.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 23 16:56:54 2017 Arthur Josso
** Last update Fri Jun 23 20:00:09 2017 Arthur Josso
*/

#include "core.h"

bool	player_consume_food(t_player *player)
{
  if (player->inventory[RES_FOOD] <= 0)
    return (false);
  player->inventory[RES_FOOD]--;
  player->starve_time = task_get_current_time()
    + ((STARVE_DURATION * 1000) / g_game->frequency);
  return (true);
}

bool	player_is_dead(t_player *player)
{
  if (player->starve_time != PLAYER_DEAD &&
      task_get_current_time() >= player->starve_time)
    {
      if (!player_consume_food(player))
	{
	  player->starve_time = PLAYER_DEAD;
	  send_cmd(CMD_PLAYER_DEAD);
	  send_graphics_cmd(CMD_GRAPHIC_DIE, player->id);
	  return (true);
	}
    }
  return (false);
}
