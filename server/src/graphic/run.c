/*
** run.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 21:04:50 2017 Arthur Josso
** Last update Tue Jun 13 17:36:15 2017 Arthur Josso
*/

#include "core.h"

static const t_entity_cmd	cmd_graphic[] =
  {
    ADD_CMD_FUNC(graphic, msz),
    ADD_CMD_FUNC(graphic, bct),
    ADD_CMD_FUNC(graphic, mct),
    ADD_CMD_FUNC(graphic, tna),
    ADD_CMD_FUNC(graphic, ppo),
    ADD_CMD_FUNC(graphic, plv),
    ADD_CMD_FUNC(graphic, pin),
    ADD_CMD_FUNC(graphic, sgt),
    ADD_CMD_FUNC(graphic, sst),
    {NULL, NULL}
  };

bool	client_graphic_run(t_graphic *graphic)
{
  exec_entity_cmd(cmd_graphic, graphic, CMD_GRAPHIC_BAD_CMD);
  return (true);
}
