/*
** init_new_player.c for init_new_player.c in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/init/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 20 21:54:28 2017 Paskal Arzel
** Last update Mon Jun 26 14:49:19 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

bool	init_new_player(void)
{
  g_core->player.level = 1;
  if (!player_inventory(NULL))
    return (false);
  g_core->player.cd_fertility = START_FERT;
  g_core->player.is_alive = true;
  return (true);
}
