/*
** admin.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun 28 17:30:27 2017 Arthur Josso
** Last update Wed Jun 28 17:53:29 2017 Arthur Josso
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
** Commands
*/

bool	cmd_admin_test(t_admin *admin, const char *arg);
