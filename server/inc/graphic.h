/*
** entity_player.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 18:03:11 2017 Arthur Josso
** Last update Tue Jun 13 16:16:00 2017 Arthur Josso
*/

#pragma once

typedef struct
{
} t_graphic;

bool	client_graphic_init();

bool	client_graphic_welcome(t_graphic *graphic);
bool    client_graphic_run(t_graphic *graphic);
bool	client_graphic_fini(t_graphic *graphic);

/*
** Argument getter
*/

bool	cmd_arg_get_pos(const char *arg, t_pos *pos);
int	cmd_arg_get_team_id(const char *arg);

/*
** Utils
*/

bool	ret_on_bad_arg();

/*
** Commands
*/

bool	cmd_graphic_msz(t_graphic *graphic, const char *arg);
bool	cmd_graphic_bct(t_graphic *graphic, const char *arg);
bool	cmd_graphic_mct(t_graphic *graphic, const char *arg);
bool	cmd_graphic_tna(t_graphic *graphic, const char *arg);
bool	cmd_graphic_ppo(t_graphic *graphic, const char *arg);
bool	cmd_graphic_plv(t_graphic *graphic, const char *arg);
bool	cmd_graphic_pin(t_graphic *graphic, const char *arg);
