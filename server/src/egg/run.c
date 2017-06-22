/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun 22 22:33:54 2017 Arthur Josso
** Last update Thu Jun 22 23:29:24 2017 Arthur Josso
*/

#include "core.h"

static bool	used_egg;
static t_player	*act_player;

static bool	search_for_available_egg(t_egg *egg)
{
  if (used_egg)
    return (true);
  if (egg->team != act_player->team)
    return (true);
  act_player->pos = egg->pos;
  egg->team->max_players--;
  return (false);
}

void	egg_can_use_one(t_player *player)
{
  used_egg = false;
  act_player = player;
  egg_for_each(&search_for_available_egg);
}

void	egg_for_each(t_egg_func callback)
{
  t_egg	*tmp;
  t_egg	*egg;

  egg = g_game->eggs;
  while (egg)
    {
      tmp = egg->next;
      if (callback(egg) == false)
        egg_rm(egg);
      egg = tmp;
    }
}

static bool	is_hatched(t_egg *egg)
{
  if (!egg->is_hatched &&
      task_get_current_time() >= egg->hatching_time)
    {
      egg->is_hatched = true;
      egg->team->max_players++;
      egg->team->players =
	cleaner_realloc(egg->team->players,
			egg->team->max_players * sizeof(t_player*));
      egg->team->players[egg->team->max_players - 1] = NULL;
      send_graphics_cmd(CMD_GRAPHIC_FORK_END, egg->id);
    }
  return (true);
}

void	egg_check_hatch()
{
  egg_for_each(&is_hatched);
}
