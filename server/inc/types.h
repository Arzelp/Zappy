/*
** types.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun  7 14:08:32 2017 Arthur Josso
** Last update Mon Jun 12 19:11:56 2017 Arthur Josso
*/

#pragma once

#include <poll.h>

typedef struct pollfd t_poll;

typedef struct
{
  int	x;
  int	y;
} t_pos;

typedef t_pos t_size;

typedef enum
  {
    RES_FOOD = 0,
    RES_LINEMATE,
    RES_DERAUMERE,
    RES_SIBUR,
    RES_MENDIANE,
    RES_PHIRAS,
    RES_THYSTAME
  } t_ressource;
