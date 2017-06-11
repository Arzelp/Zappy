/*
** entity_player.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 18:03:11 2017 Arthur Josso
** Last update Sun Jun 11 21:37:00 2017 Arthur Josso
*/

#pragma once

typedef struct s_team t_team;

typedef struct
{
  t_team	*team;
} t_player;

bool	client_player_init(t_team *team);

bool	client_player_welcome(t_player *player);
bool	client_player_run(t_player *player);
bool	client_player_fini(t_player *player);
