/*
** call_timeout.c for call_timeout in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat Jul  1 19:55:42 2017 Paskal Arzel
** Last update Sun Jul  2 18:11:54 2017 Paskal Arzel
*/

#include <time.h>
#include "core.h"

bool	call_timeout(time_t start, time_t max)
{
  time_t	now;

  now = time(NULL);
  if (now > start + max)
    return (true);
  return (false);
}
