/*
** client_io_cmd.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 17:11:02 2017 Arthur Josso
** Last update Thu Jun  8 17:41:52 2017 Arthur Josso
*/

#include <stdarg.h>
#include <stdio.h>
#include "core.h"

static t_cmd_fmt cmd_fmt[] =
  {
    {CMD_PLAYER_WELCOME, "WELCOME\n"},
    {CMD_PLAYER_NBR_FREE_SLOT, "%d\n"},
    {CMD_PLAYER_MAP_SIZE, "%d %d\n"},
    {CMD_PLAYER_OK, "ok\n"},
    {CMD_PLAYER_KO, "ko\n"},
    {CMD_PLAYER_DEAD, "dead\n"},
    {CMD_PLAYER_INCANTATION_START, "Elevation underway\n"},
    {CMD_PLAYER_INCANTATION_END, "Current level: %d\n"},
    {CMD_NONE, NULL},
  };

void		send_cmd(t_cmd_type type, ...)
{
  char		buff[BUFF_SIZE];
  int		i;
  va_list	arglist;
  int		print_ret;

  i = 0;
  while (cmd_fmt[i].type != CMD_NONE &&
	 cmd_fmt[i].type != type)
    i++;
  if (cmd_fmt[i].type != CMD_NONE)
    return;
  va_start(arglist, type);
  print_ret = vsnprintf(buff, BUFF_SIZE - 1, cmd_fmt[i].fmt, arglist);
  if (print_ret < 0 || print_ret == BUFF_SIZE - 1)
    fat_err("vsnprintf");
  buff[print_ret] = '\0';
  va_end(arglist);
  g_client->obuff = cleaner_strcat(g_client->obuff, buff);
}
