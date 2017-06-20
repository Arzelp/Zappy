/*
** look.c for look in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 20 22:11:11 2017 Paskal Arzel
** Last update Tue Jun 20 22:17:08 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

bool	look(void)
{
  if (!player_look(NULL))
    return (false);
  return (true);
}
