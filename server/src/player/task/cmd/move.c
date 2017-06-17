/*
** move.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 19:46:03 2017 Arthur Josso
** Last update Sat Jun 17 21:03:06 2017 Arthur Josso
*/

#include <stdio.h>
#include "core.h"

static const char relative_moves[DIR_NBR][COORD_NBR] =
  {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
  };

void		get_relative_pos(t_player *player, t_pos *pos, t_move move)
{
  uint8_t	relative_direction;

  relative_direction = (player->dir + move) % DIR_NBR;
  pos->x += relative_moves[relative_direction][COORD_X];
  pos->y += relative_moves[relative_direction][COORD_Y];
  pos->x %= g_game->map_size.x;
  pos->y %= g_game->map_size.y;
}

static void	move_player(t_player *player, t_move move)
{
  char		buff[BUFF_SIZE];

  get_relative_pos(player, &player->pos, move);
  send_cmd(CMD_PLAYER_OK);
  sprintf(buff, "#%d", player->id);
  for_each_graphic(&cmd_graphic_ppo, buff);
}

bool	task_forward(t_player *player, char *arg)
{
  (void)arg;
  move_player(player, MOVE_FORWARD);
  return (true);
}

bool	task_left(t_player *player, char *arg)
{
  (void)arg;
  move_player(player, MOVE_LEFT);
  return (true);
}

bool	task_right(t_player *player, char *arg)
{
  (void)arg;
  move_player(player, MOVE_RIGHT);
  return (true);
}
