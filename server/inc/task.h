/*
** task.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jun 16 19:23:40 2017 Arthur Josso
** Last update Mon Jun 19 19:36:02 2017 Arthur Josso
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "types.h"

typedef struct s_player t_player;
typedef uint64_t t_time;
typedef bool (*t_task_func)(t_player *player, char *arg);

typedef enum
  {
    TASK_FORWARD = 0,
    TASK_LEFT,
    TASK_RIGHT,
    TASK_LOOK,
    TASK_INVENTORY,
    TASK_EJECT,
    TASK_TAKE,
    TASK_SET
  } t_task_type;

typedef struct s_task t_task;

struct s_task
{
  t_task_func	func;
  t_time	exec_time;
  char		*arg;
  t_task	*next;
  t_task	*prev;
};

/*
** Core
*/

void	task_add(t_task **tasks, t_task_type type, const char *arg);
void	task_rm(t_task *task);
void	task_rm_all(t_task *task);
void	task_run(t_task **tasks);

/*
** Utils
*/

t_time	task_get_current_time();
void	get_relative_pos(t_player *player, t_pos *pos, t_move move);

/*
** List
*/

typedef struct
{
  t_task_func	func;
  uint32_t	duration;
} t_task_list;

extern const t_task_list	task_list[];

/*
** Functions
*/

bool	task_forward(t_player *player, char *arg);
bool	task_left(t_player *player, char *arg);
bool	task_right(t_player *player, char *arg);
bool	task_look(t_player *player, char *arg);
bool	task_inventory(t_player *player, char *arg);
bool	task_eject(t_player *player, char *arg);
bool	task_take(t_player *player, char *arg);
bool	task_set(t_player *player, char *arg);
