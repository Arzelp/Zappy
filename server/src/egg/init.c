/*
** init.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun 22 17:05:04 2017 Arthur Josso
** Last update Fri Jun 23 20:50:18 2017 Arthur Josso
*/

#include "core.h"

t_egg	*egg_add(t_player *layer)
{
  t_egg	*new;

   new = cleaner_malloc(sizeof(t_egg));
   new->id = g_server->egg_id++;
   new->layer_id = layer->id;
   new->pos = layer->pos;
   new->is_hatched = false;
   new->team = layer->team;
   new->hatching_time = get_current_time()
     + ((HATCHING_DURATION * 1000) / g_game->frequency);
   new->next = g_game->eggs;
   if (g_game->eggs != NULL)
     (g_game->eggs)->prev = new;
   new->prev = NULL;
   g_game->eggs = new;
   return (new);
}

void	egg_rm(t_egg *egg)
{
  if (g_game->eggs == egg)
    g_game->eggs = egg->next;
  if (egg->prev)
    egg->prev->next = egg->next;
  if (egg->next)
    egg->next->prev = egg->prev;
  cleaner_rm_addr(egg);
}
