/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Tue Jun 13 15:08:00 2017 Arthur Josso
*/

#include "core.h"

bool	cmd_graphic_tna(t_graphic *graphic, const char *arg)
{
  (void)graphic;
  (void)arg;
  send_cmd(CMD_GRAPHIC_TEAM_NAME, g_game->team[0].name);
  send_cmd(CMD_GRAPHIC_TEAM_NAME, g_game->team[1].name);
  return (true);
}
