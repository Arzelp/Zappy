/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun  9 14:40:33 2017 Arthur Josso
** Last update Wed Jun 28 17:33:13 2017 Arthur Josso
*/

#include "core.h"

bool	client_admin_welcome(t_admin *admin)
{
  (void)admin;
  g_client->callback = (t_entity_func)&client_admin_run;
  return (true);
}

bool	client_admin_init()
{
  g_client->type = ENTITY_ADMIN;
  g_client->entity = cleaner_malloc(sizeof(t_admin));
  g_client->callback = (t_entity_func)&client_admin_welcome;
  g_client->callback_dtor = (t_entity_func)&client_admin_fini;
  return (true);
}

bool	client_admin_fini(t_admin *admin)
{
  (void)admin;
  g_client->callback = &client_entity_fini;
  g_client->callback_dtor = NULL;
  return (true);
}
