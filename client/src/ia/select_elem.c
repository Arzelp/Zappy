/*
** select_elem.c for select_elem in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Fri Jun 23 16:57:02 2017 Paskal Arzel
** Last update Mon Jun 26 14:45:55 2017 Paskal Arzel
*/

#include "core.h"

int	select_primary(void)
{
  int i;
  int	res;
  int	val;

  i = 0;
  res = 0;
  val = 0;
  (void)val;
  (void)res;
  if (g_core->player.inventory[FOOD] <= MIN_SAFE_FOOD)
    return (FOOD);
  while (i < FOOD)
  {
    return (0);
  }
  return (0);
}
