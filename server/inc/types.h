/*
** types.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun  7 14:08:32 2017 Arthur Josso
** Last update Wed Jun  7 14:10:44 2017 Arthur Josso
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
