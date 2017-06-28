/*
** move.c for move in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 27 15:20:53 2017 Paskal Arzel
** Last update Tue Jun 27 17:38:08 2017 Paskal Arzel
*/

#include <math.h>
#include <stdlib.h>
#include "core.h"

static int		get_relative_value(int value, int primary, int secondary)
{
  int res;
  int i;

  res = 0;
  if (value == -1)
    return (0);
  if (primary == FOOD)
    return (value % (int)pow(10, primary));
  i = 0;
  while (i < FOOD)
  {
    if (primary == i)
	    res += PRIMARY_FACT * (value % (int)pow(10, i + 1)) / (int)pow(10, i);
    else if (secondary == i)
			res += SECONDARY_FACT * (value % (int)pow(10, i + 1)) / (int)pow(10, i);
    else
			res += (value % (int)pow(10, i + 1)) / (int)pow(10, i);
    i++;
  }
  res += (value % (int)pow(10, FOOD)) / 10;
  return (res);
}

static short	find_best_case(int **minimap, t_pos *position,
			       int primary, int secondary)
{
  short dir;
  int		maxvalue;
  int		val;

  dir = 0;
  maxvalue = get_relative_value(minimap[g_core->player.level - position->y]
    [g_core->player.level - position->x - 1], primary, secondary);
  if (g_core->player.level - position->y - 1 >= 0)
  {
    val = get_relative_value(minimap[g_core->player.level - position->y - 1]
      [g_core->player.level - position->x], primary, secondary);
    dir = (val > maxvalue) ? 1 : dir;
    maxvalue = (val > maxvalue) ? val : maxvalue;
  }
  val = get_relative_value(minimap[g_core->player.level - position->y]
    [g_core->player.level - position->x + 1], primary, secondary);
  dir = (val > maxvalue) ? 2 : dir;
  return (dir);
}

void	check_and_move(int **minimap, t_pos *position, int primary, int secondary)
{
  short	dir;
  void	(*func[4])(t_pos *);

  dir = find_best_case(minimap, position, primary, secondary);
  func[0] = &move_left;
  func[1] = &move_forward;
  func[2] = &move_right;
  func[3] = NULL;
  if (dir >= 0 && dir < 3)
    func[dir](position);
}
