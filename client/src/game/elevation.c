/*
** elevation.c for elevation in /client/src/game/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sun Jun 18 18:27:53 2017 Frederic Oddou
** Last update Mon Jun 26 16:20:39 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

const t_elevation	g_elevation[] = {
  {1, 1, {1, 0, 0, 0, 0, 0, 0}},
  {2, 2, {1, 1, 1, 0, 0, 0, 0}},
  {3, 2, {2, 0, 1, 0, 2, 0, 0}},
  {4, 4, {1, 1, 2, 0, 1, 0, 0}},
  {5, 4, {1, 2, 1, 3, 0, 0, 0}},
  {6, 6, {1, 2, 3, 0, 1, 0, 0}},
  {7, 6, {2, 2, 2, 2, 2, 0, 0}},
  {-1, -1, {-1}}
};

const t_elevation	*elevation_get_infos(void)
{
  size_t		i;

  i = 0;
  while (g_elevation[i].level != -1)
    {
      if (g_elevation[i].level == g_core->player.level)
	return (&g_elevation[i]);
    }
  return (NULL);
}

int			elevation_need_object(enum e_obj obj_id)
{
  const t_elevation	*elevation;

  if (obj_id == OBJ_NB || (elevation = elevation_get_infos()) == NULL)
    return (-1);
  return (elevation->object[obj_id]);
}
