/*
** loot_case.c for loot_case in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Mon Jun 26 17:14:32 2017 Paskal Arzel
** Last update Tue Jun 27 17:56:22 2017 Paskal Arzel
*/

#include <math.h>
#include "core.h"

void loot_case(int value)
{
  int	power;
  int took;
  int tot;

  power = FOOD;
  while (power >= 0)
  {
    took = 0;
    tot = (power == FOOD) ? (value / (int)pow(10, power)) :
    ((value % (int)pow(10, power + 1)) / (int)pow(10, power));
    while (took < tot && (power != FOOD
			|| g_core->player.inventory[FOOD] <= MAX_FOOD))
    {
      player_take(g_elem[power].name);
      took++;
    }
    power--;
  }
}
