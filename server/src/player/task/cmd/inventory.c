/*
** inventory.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 19 16:12:04 2017 Arthur Josso
** Last update Mon Jun 19 19:49:18 2017 Arthur Josso
*/

#include <stdio.h>
#include <string.h>
#include "core.h"

static void	list_inventory(t_player *player, char **buff)
{
  t_ressource	ressource;
  char		nbr_tmp[BUFF_SIZE];

  ressource = RES_FOOD;
  while (ressource != RES_NBR)
    {
      sprintf(nbr_tmp, "%s %d,", g_ressources[ressource],
	      player->inventory[ressource]);
      *buff = cleaner_strcat(*buff, nbr_tmp);
      ressource++;
    }
}

bool    task_inventory(t_player *player, char *arg)
{
  char	*buff;
  char	*tmp;

  (void)arg;
  buff = cleaner_strcat(NULL, "[");
  list_inventory(player, &buff);
  tmp = strrchr(buff, ',');
  *tmp = '\0';
  buff = cleaner_strcat(buff, " ]\n");
  g_client->obuff = cleaner_strcat(g_client->obuff, buff);
  cleaner_rm_addr(buff);
  return (true);
}

static t_ressource	parse_ressource(char *res)
{
  t_ressource		ressource;

  if (res == NULL)
    return (RES_NONE);
  ressource = RES_FOOD;
  while (ressource != RES_NBR)
    {
      if (strcasecmp(g_ressources[ressource] + 1, res) == 0)
	return (ressource);
      ressource++;
    }
  return (RES_NONE);
}

bool		task_take(t_player *player, char *arg)
{
  t_ressource	ressource;

  ressource = parse_ressource(arg);
  if (ressource == RES_NONE)
    send_cmd(CMD_PLAYER_KO);
  else if (g_game->map[player->pos.y][player->pos.x][ressource] == 0)
    send_cmd(CMD_PLAYER_KO);
  else
    {
      g_game->map[player->pos.y][player->pos.x][ressource]--;
      player->inventory[ressource]++;
      send_cmd(CMD_PLAYER_OK);
    }
  return (true);
}

bool		task_set(t_player *player, char *arg)
{
  t_ressource	ressource;

  ressource = parse_ressource(arg);
  if (ressource == RES_NONE)
    send_cmd(CMD_PLAYER_KO);
  else if (player->inventory[ressource] == 0)
    send_cmd(CMD_PLAYER_KO);
  else
    {
      player->inventory[ressource]--;
      g_game->map[player->pos.y][player->pos.x][ressource]++;
      send_cmd(CMD_PLAYER_OK);
    }
  return (true);
}
