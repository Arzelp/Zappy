/*
** inventory.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 19 16:12:04 2017 Arthur Josso
** Last update Mon Jun 19 16:40:28 2017 Arthur Josso
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
