/*
** get_message.c for get_message in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sat Jul  1 00:36:53 2017 Paskal Arzel
** Last update Sat Jul  1 18:29:55 2017 Paskal Arzel
*/

#include <string.h>
#include "core.h"

static int	get_direction(const char *data, int i)
{
  int	res;

  res = data[i] - '0';
  if (res < 0 || res > 9)
    return (-1);
  return (res);
}

static void	get_key(const char *data, int pos, t_message *message)
{
  int	i;

  i = 0;
  while (i < KEY_SIZE)
  {
    message->key[i] = data[pos + i];
    i++;
  }
}

bool		get_message(const char	*data, t_message	*message)
{
  int	i;
  int	j;
  int	pos;

  i = 0;
  j = 0;
  pos = 0;
  if (strncmp(data, "message ", strlen("message ")))
    return (false);
  i = strlen("message n, ");
  if ((message->dir = get_direction(data, strlen("message "))) == -1)
    return (false);
  get_key(data, i, message);
  i += KEY_SIZE;
  while (data[i])
  {
    message->core[j] = data[i];
    i++;
    j++;
  }
  return (true);
}
