/*
** send_message.c for send_message in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Thu Jun 29 18:33:35 2017 Paskal Arzel
** Last update Sat Jul  1 18:57:26 2017 Paskal Arzel
*/

#include <stdlib.h>
#include "core.h"

static void	encrypt(char *str, char key[KEY_SIZE])
{
  int	i;
  int	pos;
  unsigned char res;
  char	encrypted[BUFFER_SIZE];

  pos = 0;
  i = 0;
  while (str[i] && i < BUFFER_SIZE - KEY_SIZE)
  {
    res = str[i] + key[pos];
    if (res > 127)
      res -= 117;
    encrypted[i + KEY_SIZE] = (char)res;
    pos = calc_pos(pos, 1);
    i++;
  }
  encrypted[i + KEY_SIZE] = '\0';
  i = 0;
  while (i < KEY_SIZE)
  {
    encrypted[i] = key[i];
    i++;
  }
  player_broadcast(encrypted);
}

void	send_message(char *str)
{
	int	i;
  char	key[KEY_SIZE];

  i = 0;
  if (str == NULL)
    return;
  while (i < KEY_SIZE)
  {
    key[i] = 90 + i;
    i++;
  }
  encrypt(str, key);
  return;
}
