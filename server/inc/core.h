/*
** core.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:28:31 2017 Arthur Josso
** Last update Tue Jun  6 16:21:49 2017 Arthur Josso
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <poll.h>
#include "misc.h"
#include "cleaner.h"

typedef struct pollfd t_poll;
typedef struct s_client t_client;

typedef struct
{
  uint16_t	port;
  int		fd;
  t_client	*clients;
} t_server;

extern t_server	*g_server;

/*
** Parse Arguments
*/

bool	parse_arg(int ac, char **av);

/*
** Core funcs
*/

#define MAX_PENDING_CONNECTIONS	(0x100)

bool	init_server();
void	run_server();

/*
** Client Manager
*/

struct s_client
{
  int		fd;
  char		*ibuff;
  char		*obuff;
  t_client	*prev;
  t_client	*next;
};

typedef bool (*t_client_callback)(t_client *client);

typedef struct
{
  short			event;
  t_client_callback	func;
} t_poll_func;

void	client_add(int fd);
bool	client_rm(t_client *client);
void	client_for_each(t_client_callback callback);
void	client_poll_handler();

void	client_init(t_client *client, int fd);
void	client_fini(t_client *client);

/*
** Client IO
*/

#define BUFF_SIZE       (1024)

bool	write_on_client(t_client *client);
bool	read_on_client(t_client *client);

/*
** FD Manager
*/

void	fd_list_rm(int fd);
void	fd_list_add(int fd);
nfds_t	fd_list_get_nb();
t_poll	*fd_list_get();
short	fd_list_get_revents(int fd);
