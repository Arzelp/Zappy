/*
** define_entity.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 19:42:15 2017 Arthur Josso
** Last update Sun Jun 11 21:44:07 2017 Arthur Josso
*/

#include <string.h>
#include "core.h"

bool	client_entity_fini(void *entity)
{
  (void)entity;
  if (g_client->obuff[0] == '\0')
    return (false);
  return (true);
}

bool	client_entity_init(void *entity)
{
  (void)entity;
  send_cmd(CMD_WELCOME);
  g_client->callback = &client_entity_define;
  return (true);
}

bool	client_entity_define(void *entity)
{
  char	*type;

  (void)entity;
  type = recv_cmd();
  if (type == NULL)
    return (true);
  if (strcmp(type, "GRAPHIC") == 0)
    client_graphic_init();
  else if (strcmp(type, g_game->team[0].name) == 0)
    client_player_init(&g_game->team[0]);
  else if (strcmp(type, g_game->team[1].name) == 0)
    client_player_init(&g_game->team[1]);
  else
    {
      g_client->callback = &client_entity_fini;
      send_cmd(CMD_PLAYER_KO);
    }
  cleaner_rm_addr(type);
  return (true);
}
