/*
** client_io_cmd.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 17:11:02 2017 Arthur Josso
** Last update Tue Jun 13 13:40:06 2017 Arthur Josso
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "core.h"

static t_cmd_fmt cmd_fmt[] =
  {
    {CMD_WELCOME, "WELCOME\n"},
    {CMD_PLAYER_NBR_FREE_SLOT, "%d\n"},
    {CMD_PLAYER_MAP_SIZE, "%d %d\n"},
    {CMD_PLAYER_OK, "ok\n"},
    {CMD_PLAYER_KO, "ko\n"},
    {CMD_PLAYER_DEAD, "dead\n"},
    {CMD_PLAYER_INCANTATION_START, "Elevation underway\n"},
    {CMD_PLAYER_INCANTATION_END, "Current level: %d\n"},
    {CMD_GRAPHIC_BAD_CMD, "suc\n"},
    {CMD_GRAPHIC_BAD_ARG, "sbp\n"},
    {CMD_GRAPHIC_MAP_SIZE, "msz %d %d\n"},
    {CMD_GRAPHIC_TILE_CONTENT, "bct %d %d %d %d %d %d %d %d %d\n"},
    {CMD_GRAPHIC_TEAM_NAME, "tna %s\n"},
    {CMD_GRAPHIC_PLAYER_POS, "ppo #%d %d %d %d\n"},
    {CMD_GRAPHIC_PLAYER_LVL, "plv #%d %d\n"},
    {CMD_GRAPHIC_PLAYER_INVENTORY, "pin #%d %d %d %d %d %d %d %d %d %d\n"},
    {CMD_GRAPHIC_TIME_REF, "sgt %d\n"},
    {CMD_NONE, NULL},
  };

static const char	*get_fmt(t_cmd_type type)
{
  int			i;

  i = 0;
  while (cmd_fmt[i].type != CMD_NONE &&
         cmd_fmt[i].type != type)
    i++;
  if (cmd_fmt[i].type == CMD_NONE)
    return (NULL);
  return (cmd_fmt[i].fmt);
}

void		send_cmd(t_cmd_type type, ...)
{
  char		buff[BUFF_SIZE];
  va_list	arglist;
  int		print_ret;
  const char	*fmt;

  if ((fmt = get_fmt(type)) == NULL)
    return;
  va_start(arglist, type);
  print_ret = vsnprintf(buff, BUFF_SIZE - 1, fmt, arglist);
  va_end(arglist);
  if (print_ret < 0 || print_ret == BUFF_SIZE - 1)
    fat_err("vsnprintf");
  buff[print_ret] = '\0';
  g_client->obuff = cleaner_strcat(g_client->obuff, buff);
}

void		send_graphics_cmd(t_cmd_type type, ...)
{
  va_list	arglist;
  char		buff[BUFF_SIZE];
  int		print_ret;
  const char	*fmt;
  t_client	*client;

  if ((fmt = get_fmt(type)) == NULL)
    return;
  va_start(arglist, type);
  print_ret = vsnprintf(buff, BUFF_SIZE - 1, fmt, arglist);
  va_end(arglist);
  if (print_ret < 0 || print_ret == BUFF_SIZE - 1)
    fat_err("vsnprintf");
  buff[print_ret] = '\0';
  client = g_server->clients;
  while (client)
    {
      if (client->type == ENTITY_GRAPHIC)
	client->obuff = cleaner_strcat(client->obuff, buff);
      client = client->next;
    }
}

char	*recv_cmd()
{
  char	*cmd;
  char	*end;

  if (g_client->ibuff[0] == '\0')
    return (NULL);
  end = strchr(g_client->ibuff, '\n');
  if (end == NULL)
    end = strstr(g_client->ibuff, "\r\n");
  if (end == NULL)
    return (NULL);
  *end = '\0';
  if (g_client->ibuff[0] == '\0')
    cmd = NULL;
  else
    cmd = cleaner_strcat(NULL, g_client->ibuff);
  end += end[1] == '\n' ? 2 : 1;
  strmove(g_client->ibuff, end);
  return (cmd);
}
