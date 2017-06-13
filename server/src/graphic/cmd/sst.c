/*
** msz.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:00:58 2017 Arthur Josso
** Last update Tue Jun 13 17:43:17 2017 Arthur Josso
*/

#include "core.h"

bool	cmd_graphic_sst(t_graphic *graphic, const char *arg)
{
  int	freq;

  (void)graphic;
  if ((freq = cmd_arg_get_freq(arg)) == -1)
    return (ret_on_bad_arg());
  g_game->frequency = freq;
  send_cmd(CMD_GRAPHIC_TIME_REF, g_game->frequency);
  return (true);
}
