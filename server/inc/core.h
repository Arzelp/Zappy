/*
** core.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 14:28:31 2017 Arthur Josso
** Last update Fri Jun 16 19:25:13 2017 Arthur Josso
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include "player.h"
#include "graphic.h"
#include "misc.h"
#include "cleaner.h"
#include "types.h"
#include "default_values.h"
#include "task.h"

typedef struct s_client t_client;
typedef struct s_game t_game;
typedef struct s_server t_server;
typedef struct s_tile t_tile;
typedef struct s_team t_team;

extern t_server		*g_server;
extern t_game		*g_game;
extern t_client		*g_client;
extern const char	*g_ressources[];
extern uint32_t		g_player_id;

/*
** Core funcs
*/

void	init_map();
bool	init_server();
void	run_server();

/*
** Game types
*/

struct s_team
{
  const char	*name;
  t_player	**players;
  uint32_t	nbr_players;
  uint32_t	max_players;
};

struct s_game
{
  t_size	map_size;
  uint16_t	***map;
  uint32_t	max_players_init;
  uint32_t	frequency;
  t_team	**team;
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
bool    parse_f_opt(t_parse_action action);

bool    parse_arg(int ac, char **av);

void	parse_team_set_av(char **av);

/*
** Client Manager
*/

typedef bool (*t_entity_func)(void *entity);

struct s_client
{
  int		fd;
  char		*ibuff;
  char		*obuff;
  t_entity_type	type;
  void		*entity;
  t_entity_func	callback;
  t_entity_func	callback_dtor;
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

bool    client_entity_init(void *entity);
bool    client_entity_define(void *entity);
bool	client_entity_fini(void *entity);

/*
** Client IO
*/

#define BUFF_SIZE       (1024)

typedef struct
{
  t_cmd_type	type;
  const char	*fmt;
} t_cmd_fmt;

bool	write_on_client(t_client *client);
bool	read_on_client(t_client *client);

void	send_cmd(t_cmd_type type, ...);
void	send_graphics_cmd(t_cmd_type type, ...);
char	*recv_cmd();

/*
** Entity Commands
*/

#define ADD_CMD_FUNC(type, func) {#func,(t_entity_cmd_func)&cmd_##type##_##func}

typedef bool (*t_entity_cmd_func)(void *entity, const char *arg);

typedef struct s_entity_cmd
{
  const char		*name;
  t_entity_cmd_func	func;
} t_entity_cmd;

bool	exec_entity_cmd(const t_entity_cmd *cmds, void *entity,
			t_cmd_type bad_cmd);

/*
** FD Manager
*/

void	fd_list_rm(int fd);
void	fd_list_add(int fd);
nfds_t	fd_list_get_nb();
t_poll	*fd_list_get();
short	fd_list_get_revents(int fd);
