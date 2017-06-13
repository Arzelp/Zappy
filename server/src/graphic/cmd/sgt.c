/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Tue Jun 13 17:36:46 2017 Arthur Josso
*/

#include "core.h"

bool	cmd_graphic_sgt(t_graphic *graphic, const char *arg)
{
  (void)graphic;
  (void)arg;
  send_cmd(CMD_GRAPHIC_TIME_REF, g_game->frequency);
  return (true);
}
