/*
** admin.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun 28 17:30:27 2017 Arthur Josso
** Last update Fri Jun 30 13:17:20 2017 Arthur Josso
*/

#pragma once

#define ADMIN_HASH	0xb85fb95f

typedef struct
{
} t_admin;

bool	client_admin_init();

bool	client_admin_welcome(t_admin *admin);
bool	client_admin_run(t_admin *admin);
bool	client_admin_fini(t_admin *admin);

/*
** Tools
*/

uint32_t	admin_get_id(const char *s);

/*
** Commands
*/

bool	cmd_admin_list(t_admin *admin, const char *arg);
bool	cmd_admin_kill(t_admin *admin, const char *arg);
bool	cmd_admin_quit(t_admin *admin, const char *arg);
bool	cmd_admin_lvlup(t_admin *admin, const char *arg);
