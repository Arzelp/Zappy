/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Thu Jun 15 14:20:58 2017 Arthur Josso
*/

#include "core.h"

bool	cmd_graphic_tna(t_graphic *graphic, const char *arg)
{
  int	i;

  (void)graphic;
  (void)arg;
  i = 0;
  while (g_game->team[i])
    send_cmd(CMD_GRAPHIC_TEAM_NAME, g_game->team[i++]->name);
  return (true);
}
