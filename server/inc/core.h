/*
** core.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:28:31 2017 Arthur Josso
** Last update Tue Jun  6 14:55:57 2017 Arthur Josso
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "misc.h"
#include "cleaner.h"

typedef struct
{
  uint16_t	port;
} t_server;

extern t_server	*g_server;

/*
** Parse Arguments
*/

bool	parse_arg(int ac, char **av);

/*
** Core funcs
*/

void	run_server();
