/*
** ia_main.c for ia_main in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Mon Jun 19 20:13:12 2017 Paskal Arzel
** Last update Wed Jun 21 11:21:08 2017 Frederic Oddou
*/

#include <stdio.h>
#include "core.h"

bool		ia_main(void)
{
  g_core->player.is_alive = true;
  g_core->player.cd_fertility = START_FERT;
  while (g_core->player.is_alive)
    {
      if (!check_mom())
	look();
    }
  return (true);
}
