/*
** player_set.c for set in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 22:09:32 2017 Frederic Oddou
** Last update Sun Jun 18 18:04:39 2017 Frederic Oddou
*/

#include <stdio.h>
#include "core.h"
#include "utils.h"

bool		player_set(const char *str)
{
  char		buffer[BUFFER_SIZE];
  enum e_obj	obj_id;

  snprintf(buffer, BUFFER_SIZE, "Set %s", str);
  if (!send_msg(buffer))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    {
      debug_message_error("Set", str, NULL);
      return (false);
    }
  if ((obj_id = get_object_id_from_name(str)) != OBJ_NB)
    g_core->player.inventory[obj_id] -= 1;
  else
    player_inventory(NULL);
  debug_message_confirm("Set", str, NULL);
  return (true);
}
