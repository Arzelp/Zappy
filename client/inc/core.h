/*
** core.h for core in /client/inc/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 13 17:11:24 2017 Paskal Arzel
** Last update Sat Jun 17 22:25:34 2017 Frederic Oddou
*/

#pragma once

#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netdb.h>
#include "default_values.h"

#define NAME_SIZE	256
#define HOST_SIZE	2048
#define BUFFER_SIZE	2048

enum e_position
{
  POS_X,
  POS_Y,
  POS_SIZE,
};

enum e_obj
{
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  OBJ_NB
};

typedef struct
{
  char			view[(DELT_MAX_LVL * DELT_MAX_LVL) + 1][BUFFER_SIZE];
  int			client_num;
  int			inventory[OBJ_NB];
  int			level;
  int			connect_nbr;
}			t_player;

typedef struct
{
  t_player		player;
  int			map_size[POS_SIZE];
  uint16_t		port;
  char			name_team[NAME_SIZE];
  char			host[HOST_SIZE];
  int			socket_fd;
  struct sockaddr_in	port_socket;
}			t_core;

/*
** @parse
** Parse all arguments given in parameters.
*/

typedef enum
  {
    PARSE_INIT,
    PARSE_FILL,
    PARSE_CHECK
  } t_parse_action;

typedef bool (*t_parse_func)(t_parse_action action);

typedef struct
{
  char		opt;
  t_parse_func	func;
}		t_parse_opt;

bool		parse(int ac, char **av);
bool		parse_p_opt(t_parse_action action);
bool		parse_n_opt(t_parse_action action);
bool		parse_h_opt(t_parse_action action);

/*
** @connect
** - open_socket.c : Open the connection from an ip or host.
** - get_player.c : Get the position and give the team name before starting.
** - send_msg.c : Send a message to the server.
** - get_msg.c : Receive a message from the server.
*/

bool		open_socket(void);
bool		close_socket(void);
bool		get_player(void);
bool		send_msg(const char *str);
bool		receive_msg(char *str, size_t len);

/*
** @commands
*/

bool		player_forward(const char *str);
bool		player_right(const char *str);
bool		player_left(const char *str);
bool		player_broadcast(const char *str);
bool		player_look(const char *str);
bool		player_inventory(const char *str);
bool		player_eject(const char *str);
bool		player_incantation(const char *str);
bool		player_fork(const char *str);
bool		player_take(const char *str);
bool		player_set(const char *str);
bool		player_connect_nbr(const char *str);

extern t_core	*g_core;
