/*
** entity_player.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jun  8 18:03:11 2017 Arthur Josso
** Last update Mon Jun 12 22:04:02 2017 Arthur Josso
*/

#pragma once

#define IS_GRAPHIC(client)	(client->callback_dtor == \
				 (t_entity_func)&client_graphic_fini \
				 ? true : false)

typedef struct
{
} t_graphic;

bool	client_graphic_init();

bool	client_graphic_welcome(t_graphic *graphic);
bool    client_graphic_run(t_graphic *graphic);
bool	client_graphic_fini(t_graphic *graphic);

/*
** Commands
*/

bool	cmd_graphic_msz(t_graphic *graphic, const char *arg);
