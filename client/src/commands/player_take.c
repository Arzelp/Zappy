/*
** player_take.c for take in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sat Jun 17 21:54:30 2017 Frederic Oddou
** Last update Tue Jun 27 17:55:50 2017 Paskal Arzel
*/

#include <stdio.h>
#include "core.h"
#include "utils.h"

bool		player_take(const char *str)
{
  char		buffer[BUFFER_SIZE];
  enum e_obj	obj_id;

  snprintf(buffer, BUFFER_SIZE, "Take %s", str);
  if (!send_msg(buffer))
    return (false);
  if (!receive_msg(buffer, BUFFER_SIZE) || !is_answer_ok(buffer))
    {
      debug_message_error("Take", str, NULL);
      return (false);
    }
  if ((obj_id = get_object_id_from_name(str)) != OBJ_NB)
    g_core->player.inventory[obj_id] += 1;
  else
    player_inventory(NULL);
  debug_message_confirm("Take", str, NULL);
  return (true);
}
