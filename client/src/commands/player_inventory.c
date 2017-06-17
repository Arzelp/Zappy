/*
** player_inventory.c for inventory in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 21:29:39 2017 Frederic Oddou
** Last update Sat Jun 17 22:18:58 2017 Frederic Oddou
*/

#include <string.h>
#include <stdio.h>
#include "core.h"
#include "utils.h"

bool		player_inventory(const char *str)
{
  char		buffer[BUFFER_SIZE];

  (void)str;
  if (!send_msg("Inventory"))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE))
    return (false);
  bzero(g_core->player.inventory, sizeof(g_core->player.inventory));
  if (sscanf(buffer, "[ food %d, linemate %d, deraumere %d, sibur %d, "
	     "mendiane %d, phiras %d, thystame %d ]",
	     &g_core->player.inventory[FOOD],
	     &g_core->player.inventory[LINEMATE],
	     &g_core->player.inventory[DERAUMERE],
	     &g_core->player.inventory[SIBUR],
	     &g_core->player.inventory[MENDIANE],
	     &g_core->player.inventory[PHIRAS],
	     &g_core->player.inventory[THYSTAME]) != 7)
    return (false);
  return (true);
}
