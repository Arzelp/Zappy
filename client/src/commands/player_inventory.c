/*
** player_inventory.c for inventory in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 21:29:39 2017 Frederic Oddou
** Last update Wed Jun 28 16:53:27 2017 Paskal Arzel
*/

#include <string.h>
#include <stdio.h>
#include "core.h"
#include "utils.h"

static bool	player_inventory_answer_check(const char *str)
{
  if (is_answer_ko(str) ||
      sscanf(str, "[ food %d, linemate %d, deraumere %d, sibur %d, "
	     "mendiane %d, phiras %d, thystame %d ]",
	     &g_core->player.inventory[FOOD],
	     &g_core->player.inventory[LINEMATE],
	     &g_core->player.inventory[DERAUMERE],
	     &g_core->player.inventory[SIBUR],
	     &g_core->player.inventory[MENDIANE],
	     &g_core->player.inventory[PHIRAS],
	     &g_core->player.inventory[THYSTAME]) == 7)
    return (true);
  return (false);
}

bool		player_inventory(const char *str)
{
  char		buffer[BUFFER_SIZE];

  if (!send_msg("Inventory"))
    return (false);
  if (!cmd_checker(buffer, &player_inventory_answer_check))
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
    {
      debug_message_error("Inventory", str, buffer);
      return (false);
    }
  debug_message_confirm("Inventory", str, buffer);
  return (true);
}
