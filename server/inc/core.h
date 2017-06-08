/*
** core.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:28:31 2017 Arthur Josso
** Last update Thu Jun  8 17:49:09 2017 Arthur Josso
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include "misc.h"
#include "cleaner.h"
#include "types.h"

typedef struct s_client t_client;
typedef struct s_game t_game;
typedef struct s_server t_server;
typedef struct s_team t_team;

extern t_server	*g_server;
extern t_game	*g_game;
extern t_client	*g_client;

/*
** Core funcs
*/

#define MAX_PENDING_CONNECTIONS	(0x100)

bool	init_server();
void	run_server();

/*
** Game types
*/

struct s_team
{
  const char *name;
};

#define MAX_MAP_SIZE	0x400
#define MAX_PLAYERS	0x80
#define MAX_FERQUENCY	1e5

struct s_game
{
  t_size        map_size;
  uint32_t	max_players;
  uint32_t	frequency;
  t_team	team[2];
};

struct s_server
{
  uint16_t	port;
  int		fd;
  t_client	*clients;
  t_game	game;
};

/*
** Parse Arguments
*/

typedef bool (*t_parse_func)();

typedef struct
{
  char		opt;
  t_parse_func	func;
} t_parse_opt;

typedef enum
  {
    PARSE_INIT,
    PARSE_FILL,
    PARSE_CHECK
  } t_parse_action;

bool	parse_p_opt(t_parse_action action);
bool    parse_x_opt(t_parse_action action);
bool    parse_y_opt(t_parse_action action);
bool    parse_n_opt(t_parse_action action);
bool    parse_c_opt(t_parse_action action);
bool    parse_t_opt(t_parse_action action);

bool    parse_arg(int ac, char **av);

/*
** Client Manager
*/

struct s_client
{
  int		fd;
  char		*ibuff;
  char		*obuff;
  void		*entity;
  t_client	*prev;
  t_client	*next;
};

typedef bool (*t_entity_callback)(void *entity);
typedef bool (*t_client_callback)(t_client *client);

typedef struct
{
  short			event;
  t_client_callback	func;
} t_poll_func;

void	client_add(int fd);
bool	client_rm(t_client *client);
void	client_for_each(t_entity_callback callback);
void	client_poll_handler();

void	client_init(t_client *client, int fd);
void	client_fini(t_client *client);

/*
** Client IO
*/

#define BUFF_SIZE       (1024)

typedef enum
  {
    CMD_NONE,
    CMD_PLAYER_WELCOME,
    CMD_PLAYER_NBR_FREE_SLOT,
    CMD_PLAYER_MAP_SIZE,
    CMD_PLAYER_OK,
    CMD_PLAYER_KO,
    CMD_PLAYER_DEAD,
    CMD_PLAYER_INCANTATION_START,
    CMD_PLAYER_INCANTATION_END
  } t_cmd_type;

typedef struct
{
  t_cmd_type	type;
  const char	*fmt;
} t_cmd_fmt;

bool	write_on_client(t_client *client);
bool	read_on_client(t_client *client);

void	send_cmd(t_cmd_type type, ...);

/*
** FD Manager
*/

void	fd_list_rm(int fd);
void	fd_list_add(int fd);
nfds_t	fd_list_get_nb();
t_poll	*fd_list_get();
short	fd_list_get_revents(int fd);
