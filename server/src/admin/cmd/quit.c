/*
** test.c for lo in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun 28 17:35:38 2017 Arthur Josso
** Last update Fri Jun 30 12:28:40 2017 Arthur Josso
*/

#include "core.h"

bool    cmd_admin_quit(t_admin *admin, const char *arg)
{
  (void)admin;
  (void)arg;
  g_client->callback = &client_entity_fini;
  return (false);
}
