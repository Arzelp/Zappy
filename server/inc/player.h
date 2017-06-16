/*
** entity_player.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 18:03:11 2017 Arthur Josso
** Last update Fri Jun 16 18:57:27 2017 Arthur Josso
*/

#pragma once

#include "types.h"

typedef struct s_team t_team;

typedef struct
{
  uint32_t	id;
  t_direction	dir;
  uint8_t	lvl;
  t_pos		pos;
  uint16_t	inventory[RES_NBR];
  t_team	*team;
} t_player;

bool	client_player_init(t_team *team);

bool	client_player_welcome(t_player *player);
bool	client_player_run(t_player *player);
bool	client_player_fini(t_player *player);

/*
** Commands
*/

bool	cmd_player_Connect_nbr(t_player *player, const char *arg);
