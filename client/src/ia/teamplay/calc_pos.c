/*
** calc_pos.c for calc_pos in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 22:09:07 2017 Paskal Arzel
** Last update Sat Jul  1 18:18:00 2017 Paskal Arzel
*/

#include "core.h"

int	calc_pos(int pos, char dec)
{
  pos += dec;
  if (pos == KEY_SIZE)
    return (0);
  return (pos);
}
