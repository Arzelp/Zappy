/*
** execute_call.c for execute_call in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 00:05:20 2017 Paskal Arzel
** Last update Sun Jul  2 18:12:50 2017 Paskal Arzel
*/

#include <stdlib.h>
#include <string.h>
#include "core.h"

static int		find_call(t_message *message, int pos)
{
  int	i;

  i = 0;
  while (g_call[i].id != -1)
    {
      if (!strncmp(g_call[i].name,
        &(message->core[pos]), strlen(g_call[i].name)))
        return (i);
      i++;
    }
  return (-1);
}

bool	execute_call(t_message *message, int pos)
{
  bool	(*func[NB_CALLS + 1])(void);
  int		nb_call;

  func[0] = &exec_call;
  func[1] = &exec_counter;
  func[2] = &exec_regroup;
  func[3] = NULL;
  if ((nb_call = find_call(message, pos)) == -1 || nb_call >= NB_CALLS)
    return (false);
  return (func[nb_call]());
}
