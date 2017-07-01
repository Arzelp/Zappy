/*
** read_message.c for read_message in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 18:07:22 2017 Paskal Arzel
** Last update Sat Jul  1 18:57:36 2017 Paskal Arzel
*/

#include "core.h"

void	decrypt_message(t_message *message)
{
  int		i;
  int		pos;
  char	res;

  i = 0;
  pos = 0;
  while (message->core[i])
  {
    res = message->core[i] - message->key[pos];
    if (res < 10)
	    res += 117;
    message->core[i] = (char)res;
    pos = calc_pos(pos, 1);
    i++;
  }
  message->core[i] = '\0';
}

void	read_message(const char *data)
{
  t_message	message;

  get_message(data, &message);
  decrypt_message(&message);
}
