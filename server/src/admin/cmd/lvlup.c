/*
** test.c for lo in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun 28 17:35:38 2017 Arthur Josso
** Last update Fri Jun 30 13:16:56 2017 Arthur Josso
*/

#include "core.h"

static uint32_t	concerned_id;

static bool	lvlup_player(t_player *player)
{
  if (player->id == concerned_id &&
      player->lvl < 8)
    {
      player->lvl++;
      concerned_id = BAD_ID;
    }
  return (true);
}

bool	cmd_admin_lvlup(t_admin *admin, const char *arg)
{
  (void)admin;
  if ((concerned_id = admin_get_id(arg)) == BAD_ID)
    return (true);
  player_for_each(true, &lvlup_player);
  if (concerned_id == BAD_ID)
    send_cmd(CMD_ADMIN_CMD_OK);
  else
    send_cmd(CMD_ADMIN_CMD_KO);
  return (true);
}
