/*
** is_object.c for is_object in /client/src/utils/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Mon Jun 19 13:02:41 2017 Frederic Oddou
** Last update Mon Jun 19 13:05:16 2017 Frederic Oddou
*/

#include <string.h>
#include "core.h"
#include "utils.h"

bool		is_object_on_case(const char *str, enum e_obj obj)
{
  const char	*obj_name;

  if ((obj_name = get_object_name_from_type(obj)) == NULL)
    return (false);
  if (strstr(str, obj_name))
    return (true);
  return (false);
}
