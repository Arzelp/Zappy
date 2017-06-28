/*
** select_elem.c for select_elem in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Fri Jun 23 16:57:02 2017 Paskal Arzel
** Last update Tue Jun 27 16:32:34 2017 Paskal Arzel
*/

#include "core.h"

int	select_primary(void)
{
  int i;
  int	res;
  int	val;
  int max;
  const t_elevation	*need;

  i = 0;
  res = -1;
  val = 0;
  max = 0;
  if (g_core->player.inventory[FOOD] <= MIN_SAFE_FOOD)
    return (FOOD);
  need = elevation_get_infos();
  while (i < FOOD)
  {
    if ((val = g_core->player.inventory[i] - need->object[i]) < 0)
    {
      max = (max > val) ? val : max;
      res = i;
    }
    i++;
  }
  return (res);
}

int select_secondary(int primary)
{
  int i;
  int	res;
  int	val;
  int max;
  const t_elevation	*need;

  i = 0;
  res = -1;
  val = 0;
  max = 0;
  need = elevation_get_infos();
  while (i < FOOD)
  {
    if ((val = g_core->player.inventory[i] - need->object[i]) < 0
	  && primary != i)
    {
      max = (max > val) ? val : max;
      res = i;
    }
    i++;
  }
  return (res);
}
