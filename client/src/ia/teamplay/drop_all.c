/*
** drop_all.c for drop_all in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 14:44:25 2017 Paskal Arzel
** Last update Sun Jul  2 17:09:35 2017 Paskal Arzel
*/

#include <time.h>
#include "core.h"

static void	wait_confirmation(void)
{
  char	msg[BUFFER_SIZE];
  t_message	message;
  time_t	start;
  bool	ended;

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "loot ok.");
  ended = false;
  while (!ended && !call_timeout(start, STANDARD_TIMEOUT))
  {
    check_message(&message);
    printf("message : %s\n", message.core);
    if (!strcmp(msg, message.core))
			ended = true;
  }
  if (ended)
    printf("Ok confirmation\n");
  return;
}

void	drop_all(void)
{
  int	i;
  int	objs;

  i = 0;
  while (i < FOOD)
  {
    objs = g_core->player.inventory[i];
    while (objs)
    {
      player_set(g_elem[i].name);
      objs--;
    }
    i++;
  }
  printf("dropped all.\n");
  wait_confirmation();
  level_up_noob();
}
