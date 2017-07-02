/*
** cmd_checker.c for cmd checker in /client/src/commands/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Wed Jun 28 09:27:08 2017 Frederic Oddou
** Last update Thu Jun 29 17:44:51 2017 Frederic Oddou
*/

#include <stdio.h>
#include <string.h>
#include "core.h"
#include "utils.h"

bool		cmd_ok_or_ko(const char *str)
{
  if (is_answer_ko(str) || is_answer_ok(str))
    return (true);
  return (false);
}

bool		cmd_checker(char *buffer, bool (*func_check)(const char *str))
{
  while (receive_msg(buffer, BUFFER_SIZE))
    {
      if (func_check(buffer))
	return (true);
      else
	{
	  if (strlen(buffer))
	    {
	      debug_message("Adding to Broadcast Queue", buffer);
	      g_core->queue.push(&g_core->queue, strdup(buffer));
	    }
	}
    }
  return (false);
}
