/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun  9 14:40:33 2017 Arthur Josso
** Last update Sun Jun 11 21:55:47 2017 Arthur Josso
*/

#include "core.h"

bool	client_graphic_welcome(t_graphic *graphic)
{
  (void)graphic;
  g_client->callback = (t_entity_func)&client_graphic_run;
  return (true);
}

bool	client_graphic_init()
{
  g_client->entity = cleaner_malloc(sizeof(t_graphic));
  g_client->callback = (t_entity_func)&client_graphic_welcome;
  g_client->callback_dtor = (t_entity_func)&client_graphic_fini;
  return (true);
}

bool	client_graphic_fini(t_graphic *graphic)
{
  (void)graphic;
  g_client->callback = &client_entity_fini;
  g_client->callback_dtor = NULL;
  return (true);
}
