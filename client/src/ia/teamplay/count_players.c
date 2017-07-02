/*
** count_players.c for count_players in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:13:43 2017 Paskal Arzel
** Last update Sun Jul  2 14:19:41 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

int	count_players()
{
  player_look(NULL);
  return (count_player(g_core->player.view[0]));
}

bool	has_players(int players)
{
  printf("players on case : %d\n", count_players());
  if (count_players() >= players)
    return (true);
  return (false);
}
