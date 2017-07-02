/*
** get_nb_players.c for get_nb_players in /home/paskal/rendu/System_Unix/PSU_2016_zappy/client/src/ia/teamplay/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Sun Jul  2 17:41:59 2017 Paskal Arzel
** Last update Sun Jul  2 17:57:31 2017 Paskal Arzel
*/

#include "core.h"

int	get_nb_players(void)
{
  const t_elevation *need;

  need = elevation_get_infos_lvl(g_core->player.level);
  return (need->nb_player);
}
