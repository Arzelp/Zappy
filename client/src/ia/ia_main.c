/*
** ia_main.c for ia_main in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Mon Jun 19 20:13:12 2017 Paskal Arzel
** Last update Wed Jun 28 18:10:31 2017 Paskal Arzel
*/

#include <stdio.h>
#include <stdlib.h>
#include "core.h"

/*static void randomize()
{
  bool (*func[6])(const char *);

  func[0] = &player_inventory;
  func[1] = &player_left;
  func[2] = &player_right;
  func[3] = &player_forward;
  func[4] = &player_look;
  func[5] = NULL;
  func[rand() % 5](NULL);
}*/

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
