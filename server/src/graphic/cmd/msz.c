/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Tue Jun 13 11:04:12 2017 Arthur Josso
*/

#include "core.h"

bool	cmd_graphic_msz(t_graphic *graphic, const char *arg)
{
  (void)graphic;
  (void)arg;
  send_cmd(CMD_GRAPHIC_MAP_SIZE, g_game->map_size.x, g_game->map_size.y);
  return (true);
}
