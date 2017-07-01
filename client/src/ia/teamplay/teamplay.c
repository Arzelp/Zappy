/*
** teamplay.c for teamplay in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 16:18:45 2017 Paskal Arzel
** Last update Sat Jul  1 18:52:48 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <string.h>
#include "core.h"

static bool		check_message(void)
{
  const char	*data;

  while ((data = g_core->queue.front(&g_core->queue)))
  {
    g_core->queue.pop(&g_core->queue);
    if (!strncmp(data, "message ", strlen("message ")))
    {
      read_message(data);
      return (true);
    }
  }
  return (false);
}

bool		manage_message(void)
{
  check_message();
  send_message("Fredou est une grosse pute mais ca on le savait tous parce que d'apres la reciproque de ta mere la grosse catin on est tous noir dans ce monde de blancs kappa lolmdr 123452520958208520982072067620");
  return (false);
}
