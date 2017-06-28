/*
** move.c for move in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 27 15:45:01 2017 Paskal Arzel
** Last update Tue Jun 27 16:34:59 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

void	move_left(t_pos *position)
{
  player_left(NULL);
  player_forward(NULL);
  player_right(NULL);
  position->x += 1;
  return;
}

void	move_forward(t_pos *position)
{
  player_forward(NULL);
  position->y += 1;
  return;
}

void	move_right(t_pos *position)
{
  player_right(NULL);
  player_forward(NULL);
  player_left(NULL);
  position->x -= 1;
  return;
}
