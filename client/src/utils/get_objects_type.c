/*
** get_objects_type.c for objects type in /client/src/utils/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 21:55:59 2017 Frederic Oddou
** Last update Sat Jun 17 22:15:44 2017 Frederic Oddou
*/

#include <string.h>
#include "core.h"
#include "utils.h"

static const t_get_objects_type	g_get_objects_type[] = {
  {FOOD, "food"},
  {LINEMATE, "linemate"},
  {DERAUMERE, "deraumere"},
  {SIBUR, "sibur"},
  {MENDIANE, "mendiane"},
  {PHIRAS, "phiras"},
  {THYSTAME, "thystame"},
  {OBJ_NB, NULL}
};

const char	*get_object_name_from_type(enum e_obj obj_id)
{
  size_t	i;

  i = 0;
  while (g_get_objects_type[i].name != NULL)
    {
      if (g_get_objects_type[i].obj_id == obj_id)
	return (g_get_objects_type[i].name);
      i++;
    }
  return (NULL);
}

enum e_obj	get_object_id_from_name(const char *name)
{
  size_t	i;

  i = 0;
  while (g_get_objects_type[i].name != NULL)
    {
      if (!strcmp(g_get_objects_type[i].name, name))
	return (g_get_objects_type[i].obj_id);
      i++;
    }
  return (OBJ_NB);
}
