/*
** teamplay.c for teamplay in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 16:18:45 2017 Paskal Arzel
** Last update Thu Jun 29 17:26:26 2017 Paskal Arzel
*/

#include "core.h"

bool		manage_message(void)
{
  printf("Going to send a message");
  player_broadcast("Testing message.\n");
  return (false);
}
