/*
** debug.c for debug in /client/src/utils/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Sun Jun 18 17:51:14 2017 Frederic Oddou
** Last update Sun Jun 18 18:13:23 2017 Frederic Oddou
*/

#include <stdio.h>
#include "utils.h"

void		debug_message_confirm(const char *action, const char *opt,
				      const char *answer)
{
  char		buffer[BUFFER_SIZE];

  if (DEBUG)
    {
      snprintf(buffer, BUFFER_SIZE, "[\e[33m%s\e[0m]", action);
      fprintf(stderr, "%s %-25s", DEBUG_OK, buffer);
      if (opt)
	fprintf(stderr, "[Option %s]", opt);
      if (answer)
	fprintf(stderr, "[Answer \"%s\"]", answer);
      fprintf(stderr, "\n");
    }
}

void		debug_message_error(const char *action, const char *opt,
				    const char *answer)
{
  char		buffer[BUFFER_SIZE];

  if (DEBUG)
    {
      snprintf(buffer, BUFFER_SIZE, "[\e[33m%s\e[0m]", action);
      fprintf(stderr, "%s %-25s", DEBUG_KO, buffer);
      if (opt)
	fprintf(stderr, "[Option %s]", opt);
      if (answer)
	fprintf(stderr, "[Answer \"%s\"]", answer);
      fprintf(stderr, "\n");
    }
}
