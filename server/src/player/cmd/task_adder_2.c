/*
** task_adder_2.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun 20 13:54:50 2017 Arthur Josso
** Last update Wed Jun 21 10:53:24 2017 Arthur Josso
*/

#include <stdio.h>
#include <string.h>
#include "core.h"

static char	*incantation_list_concerned_players(t_player *player)
{
  t_client	*client;
  t_player	*other;
  char		*list;
  char		buff[BUFF_SIZE];

  list = NULL;
  client = g_server->clients;
  while (client)
    {
      if (client->type == ENTITY_PLAYER)
        {
          other = client->entity;
          if (other->lvl == player->lvl &&
              other->pos.x == player->pos.x &&
              other->pos.y == player->pos.y)
	    {
	      sprintf(buff, "#%d ", other->id);
	      list = cleaner_strcat(list, buff);
	    }
        }
      client = client->next;
    }
  list[strlen(list) - 1] = '\0';
  return (list);
}

bool    cmd_player_Incantation(t_player *player, const char *arg)
{
  char	*concerned_players;

  send_cmd(CMD_PLAYER_INCANTATION_START);
  task_add(&player->tasks, TASK_INCANTATION, arg);
  concerned_players = incantation_list_concerned_players(player);
  send_graphics_cmd(CMD_GRAPHIC_INCANTATION_START,
		    player->pos.x, player->pos.y,
		    player->lvl, concerned_players);
  cleaner_rm_addr(concerned_players);
  return (true);
}

bool    cmd_player_Broadcast(t_player *player, const char *arg)
{
  task_add(&player->tasks, TASK_BROADCAST, arg);
  return (true);
}
