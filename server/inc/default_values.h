/*
** default_values.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun  9 14:57:01 2017 Arthur Josso
** Last update Fri Jun 23 20:43:57 2017 Arthur Josso
*/

#pragma once

/*
** Static limits
*/

#define MAX_PARALLEL_TASKS	10

#define MAX_PENDING_CONNECTIONS	0x100

#define MAX_MAP_SIZE		0x400
#define MAX_PLAYERS		0x80
#define MAX_FREQUENCY		1e5

/*
** Default game values
*/

#define DFLT_SERVER_PORT	4242
#define DFLT_MAP_SIZE_X		16
#define DFLT_MAP_SIZE_Y		16
#define DFLT_MAX_PLAYERS	2
#define DFLT_FREQUENCY		100

#define DROP_PROBABILITY	24

#define MAX_PLAYER_LVL		8

#define NBR_OP_PLAYERS_TO_WIN	6
