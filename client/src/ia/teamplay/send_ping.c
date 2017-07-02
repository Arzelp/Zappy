/*
** send_ping.c for send_ping in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:21:22 2017 Paskal Arzel
** Last update Sun Jul  2 18:10:51 2017 Paskal Arzel
*/

#include <stdio.h>
#include "core.h"

void	send_ping(void)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s %d C %s", g_core->name_team,
  g_core->player.level, "ping.");
  send_message(msg);
}
