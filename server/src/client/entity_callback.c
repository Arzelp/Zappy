/*
** define_entity.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 19:42:15 2017 Arthur Josso
** Last update Wed Jun 28 17:57:14 2017 Arthur Josso
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

static bool	check_for_teams(char *type)
{
  int		i;

  i = 0;
  while (g_game->team[i])
    {
      if (strcmp(type, g_game->team[i]->name) == 0)
        {
          client_player_init(g_game->team[i]);
          cleaner_rm_addr(type);
          return (true);
        }
      i++;
    }
  return (false);
}

bool	client_entity_define(void *entity)
{
  char	*type;

  (void)entity;
  type = recv_cmd();
  if (type == NULL)
    return (true);
  if (hash_djb2(type) == ADMIN_HASH)
    {
      client_admin_init();
      cleaner_rm_addr(type);
      return (true);
    }
  if (strcmp(type, "GRAPHIC") == 0)
    {
      client_graphic_init();
      cleaner_rm_addr(type);
      return (true);
    }
  if (check_for_teams(type))
    return (true);
  g_client->callback = &client_entity_fini;
  send_cmd(CMD_PLAYER_KO);
  cleaner_rm_addr(type);
  return (true);
}
