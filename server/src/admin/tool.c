/*
** tool.c for lo in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 30 13:13:54 2017 Arthur Josso
** Last update Fri Jun 30 13:15:50 2017 Arthur Josso
*/

#include <stdlib.h>
#include "core.h"

uint32_t	admin_get_id(const char *s)
{
  if (!s || !*s || !is_nbr(s))
    {
      send_cmd(CMD_ADMIN_CMD_KO);
      return (BAD_ID);
    }
  return (atoi(s));
}
