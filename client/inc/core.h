/*
** core.h for core in /client/inc/
**
** Made by Paskal Arzel
** Login   <paskal.arzel@epitech.eu>
**
** Started on  Tue Jun 13 17:11:24 2017 Paskal Arzel
** Last update Sun Jul  2 18:19:05 2017 Paskal Arzel
*/

#pragma once

#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netdb.h>
#include "default_values.h"
#include "utils.h"

enum e_position
{
  POS_X,
  POS_Y,
  POS_SIZE,
};

enum e_obj
{
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  FOOD,
  OBJ_NB
};

typedef struct
{
  int			level;
  int			nb_player;
  enum e_obj		object[OBJ_NB];
}			t_elevation;

typedef struct
{
  int			id;
  char			*name;
}			t_elem;

typedef struct
{
  int			x;
  int			y;
}			t_pos;

typedef struct
{
  int			dir;
  char			key[KEY_SIZE];
  char			core[BUFFER_SIZE];
}			t_message;

typedef struct
{
  int			id;
  char		*name;
}t_call;

typedef struct
{
  char			view[(DELT_MAX_LVL * DELT_MAX_LVL) + 1][BUFFER_SIZE];
  char			call[MAX_CALLS][BUFFER_SIZE];
  char			rush[MAX_RUSH];
  int				client_num;
  int				inventory[OBJ_NB];
  int				level;
  int				cd_captain;
  int				connect_nbr;
  int				cd_fertility;
  int				need_player;
  bool    	is_alive;
  bool			ended_tp;
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
  t_queue		queue;
}			t_core;

/*
** @core.c
*/

void		core_init(t_core *core);
void		core_destruct();
void		core_usage(const char *name);

/*
** @connect
** - open_socket.c : Open the connection from an ip or host.
** - close_socket.c : Close the fd socket after used.
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
** For each command, the function send the command and wait for the answer.
** The functions treat and return if the command succed.
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
bool		cmd_checker(char *buffer, bool (*func_check)(const char *str));
bool		cmd_ok_or_ko(const char *str);

/*
** @game
**
** @elevation.c
** - elevation_get_infos : Get the struct that contains all information we need
**   for the next elevation.
** - elevation_need_object : Give a obj_id in parameters and the function
**   return the number of this object that we need for the next elevation.
*/

const t_elevation	*elevation_get_infos(void);
const t_elevation	*elevation_get_infos_lvl(int lvl);
int			elevation_need_object(enum e_obj obj_id);

/*
** @bot
**
** @ia_main.c
** Start the player
**
*/

bool		ia_main(void);
bool		check_mom(void);
bool		init_new_player(void);
bool		look(void);
bool		set_rush(void);
int		select_primary(void);
int 		select_secondary(int primary);
int		**set_minimap(void);
void 		loot_case(int value);
void		check_and_move(int **minimap, t_pos *position,
			       int primary, int secondary);
void		move_left(t_pos *position);
void		move_forward(t_pos *position);
void		move_right(t_pos *position);
void		elevate(void);
int		calc_value(char *str);
int		count_player(char *str);

/*
** @message
**   -teamplay.c : Check if a message has been sent.
**   -read_message.c : Decrypt the message.
**   -action.c : Make a decision and an action from the message.
**   -send_message.c : Encrypt and send a message.
*/

bool			manage_message(void);
bool			check_message(t_message *message);
void			read_message(t_message *message, const char *data);
void			send_message(char *str);
int				calc_pos(int pos, char dec);
bool			get_message(const char	*data, t_message	*message);
void			lead_team(void);
bool			call_timeout(time_t start, time_t max);
void			listen_calls(t_message *message);
bool			execute_call(t_message *message, int pos);
bool			exec_call(void);
bool			exec_counter(void);
void			group_elevation(t_message	*message);
bool			has_players(int players);
int				count_players(void);
void			loot(char	*str);
void			send_ping(void);
bool			wait_pongs(t_message	*message);
bool			exec_regroup(void);
void			change_dir(t_message *message);
void			force_loot(char	*str);
void			drop_all(void);
void			level_up_noob(void);
void			level_up_captain(void);
int				get_nb_players(void);
bool			check_ressources(t_message	*message);

extern t_core		*g_core;
extern t_elem		g_elem[];
extern t_call		g_call[];
