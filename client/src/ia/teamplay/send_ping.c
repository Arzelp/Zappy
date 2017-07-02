/*
** send_ping.c for send_ping in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 11:21:22 2017 Paskal Arzel
** Last update Sun Jul  2 11:24:13 2017 Paskal Arzel
*/

#include <stdio.h>
#include "core.h"

void	send_ping(void)
{
  char	msg[BUFFER_SIZE];

  snprintf(msg, BUFFER_SIZE, "%s C %s", g_core->name_team, "ping.");
  send_message(msg);
}
