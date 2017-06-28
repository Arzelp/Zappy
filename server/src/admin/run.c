/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 21:04:50 2017 Arthur Josso
** Last update Wed Jun 28 17:35:17 2017 Arthur Josso
*/

#include "core.h"

static const t_entity_cmd	cmd_admin[] =
  {
    ADD_CMD_FUNC(admin, test),
    {NULL, NULL}
  };

bool	client_admin_run(t_admin *admin)
{
  exec_entity_cmd(cmd_admin, admin, CMD_ADMIN_BAD_CMD);
  return (true);
}
