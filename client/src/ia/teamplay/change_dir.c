/*
** change_dir.c for change_dir in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:49:42 2017 Paskal Arzel
** Last update Sun Jul  2 12:34:34 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

void	change_dir(t_message *message)
{
  if (message->dir == 1 || message->dir == 2 || message->dir == 8)
    return;
  if (message->dir == 5)
  {
    player_right(NULL);
    player_right(NULL);
    return;
  }
  if (message->dir < 5)
  {
    player_left(NULL);
    return;
  }
  player_right(NULL);
  return;
}
