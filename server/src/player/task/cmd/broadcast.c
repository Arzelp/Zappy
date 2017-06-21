/*
** broadcast.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun 20 17:30:52 2017 Arthur Josso
** Last update Tue Jun 20 21:47:00 2017 Arthur Josso
*/

#include <math.h>
#include "core.h"

static char		*txt;

static t_player		*act_player;

static const int8_t	maps[9][COORD_NBR] =
  {
    {-1, -1},
    {0, -1},
    {1, -1},
    {-1, 0},
    {0, 0},
    {1, 0},
    {-1, 1},
    {0, 1},
    {1, 1}
  };

static const float	pi_dir[DIR_NBR] =
  {
    -(3.0 * M_PI) / 4.0,
    -M_PI / 4.0,
    M_PI / 4.0,
    (3.0 * M_PI) / 4.0
  };

static t_pos	find_nearest_pos(t_pos pos)
{
  t_pos		ret;
  t_pos		tmp_pos;
  int		i;
  float		size;
  float		tmp_size;

  ret.x = act_player->pos.x + (g_game->map_size.x * maps[0][COORD_X]);
  ret.y = act_player->pos.y + (g_game->map_size.y * maps[0][COORD_Y]);
  size = GET_DIST(ret.x, ret.y, pos.x, pos.y);
  i = 1;
  while (i < 9)
    {
      tmp_pos.x = act_player->pos.x + (g_game->map_size.x * maps[i][COORD_X]);
      tmp_pos.y = act_player->pos.y + (g_game->map_size.y * maps[i][COORD_Y]);
      tmp_size = GET_DIST(tmp_pos.x, tmp_pos.y, pos.x, pos.y);
      if (tmp_size < size)
	{
	  ret = tmp_pos;
	  size = tmp_size;
	}
      i++;
    }
  return (ret);
}

static t_direction	define_direction(t_pos p1, t_pos p2)
{
  float			angle;
  int			i;
  t_pos			pos;

  pos.x = p2.x - p1.x;
  pos.y = p2.y - p1.y;
  pos.y *= -1;
  if (pos.x == 0 && pos.y == 0)
    return (DIR_NORTH);
  angle = atan2(pos.y, pos.x);
  i = 0;
  while (i < DIR_NBR)
    {
      if (angle < pi_dir[i])
	return (((DIR_NBR - i) + 3) % DIR_NBR);
      i++;
    }
  return (DIR_WEST);
}

static bool	run_broadcast(t_client *client)
{
  t_player	*player;
  t_pos		nearest;
  t_direction	direction;

  if (client->type != ENTITY_PLAYER || client->entity == act_player)
    return (true);
  player = client->entity;
  nearest = find_nearest_pos(player->pos);
  direction = define_direction(player->pos, nearest);
  send_cmd(CMD_PLAYER_BROADCAST, direction, txt);
  return (true);
}

bool	task_broadcast(t_player *player, char *arg)
{
  if (arg == NULL || arg[0] == '\0')
    {
      send_cmd(CMD_PLAYER_KO);
      return (true);
    }
  txt = arg;
  act_player = player;
  client_for_each(&run_broadcast);
  send_graphics_cmd(CMD_GRAPHIC_BROADCAST, player->id, arg);
  return (true);
}
