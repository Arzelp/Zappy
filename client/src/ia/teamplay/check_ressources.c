/*
** check_ressources.c for check_ressources in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 06:05:42 2017 Paskal Arzel
** Last update Sun Jul  2 16:18:49 2017 Paskal Arzel
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "core.h"

static bool	has_enough(t_elevation *need, t_elevation got)
{
  int	i;

  i = 0;
  while (i <= FOOD)
  {
    printf("%s : %d\n", g_elem[i].name, got.object[i]);
    if (need->object[i] > got.object[i])
			return (false);
    i++;
  }
  return (true);
}

static bool	is_count(t_message *message)
{
  char				msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s N Ressources : ", g_core->name_team);
  if (strncmp(msg, message->core, strlen(msg)))
    return (false);
  return (true);
}

static t_elevation	update_count(t_message *message, t_elevation got)
{
  int			i;
  int			len;
  char		msg[BUFFER_SIZE];

  len = strlen(msg);
  i = len;
  if (!is_count(message))
    return (got);
  while (i <= len + FOOD)
    {
      if (message->core[i] <= '9' && message->core[i] >= '0')
        got.object[i - len] += message->core[i] - '0';
      i++;
    }
  printf("\n");
  return (got);
}

static void	call_count(void)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, COUNTER);
  send_message(msg);
}

bool	check_ressources(t_message	*message)
{
  t_elevation	*need;
  t_elevation	got;
  time_t			start;
  int					i;
  int					counter;

  call_count();
  need = elevation_get_infos_lvl(0);
  start = time(NULL);
  counter = 1;
  i = 0;
  while (i <= FOOD)
  {
    printf("my %s : %d\n", g_elem[i].name, g_core->player.inventory[i]);
    got.object[i] = g_core->player.inventory[i];
    i++;
  }
  while	(!call_timeout(start, STANDARD_TIMEOUT) && counter < NB_PLAYER_CALL)
  {
    check_message(message);
    counter += is_count(message);
    got = update_count(message, got);
  }
  return (has_enough(need, got));
}
