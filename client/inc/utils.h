/*
** utils.h for utils in /client/inc/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 11:11:42 2017 Frederic Oddou
** Last update Wed Jun 28 10:12:36 2017 Frederic Oddou
*/

#pragma once

#include <stdbool.h>
#include "default_values.h"

/*
** @checker.c
*/

bool		is_nbr(const char *s);
bool		is_answer_ok(const char *s);
bool		is_answer_ko(const char *s);

/*
** @strtok_single.c
** - The function could return an empty string if the string contrain several
** delimiters.
*/

char		*strtok_single(char *str, char const *delims);

/*
** @trim.c
** - The function deletes the extra spaces.
*/

char		*trim(char *str);

/*
** @replace_letter.c
** - Replace into the string passed as parameter, a char by an other one.
*/

char		*replace_letter(char *str, char find, char replace);

/*
** @get_objects_type.c
*/

typedef struct
{
  short		obj_id;
  const char	*name;
}		t_get_objects_type;

const char	*get_object_name_from_type(short obj_id);
short		get_object_id_from_name(const char *name);

extern const t_get_objects_type g_get_objects_type[];

/*
** @debug.c
*/

#define DEBUG_OK	"[\e[32mOK\e[0m]"
#define DEBUG_KO	"[\e[31mKO\e[0m]"

void		debug_message_confirm(const char *action, const char *opt,
				      const char *answer);
void		debug_message_error(const char *action, const char *opt,
				    const char *answer);
void		debug_message(const char *type, const char *str);

/*
** @is_object.c
** - is_object_on_case : Return true if the object is found on the case.
*/

bool		is_object_on_case(const char *str, short obj);

/*
** @queue.c
** - queue is like a cpp class but translated.
*/

typedef struct		s_queue_data
{
  void			*val;
  struct s_queue_data	*next;
}			t_queue_data;

typedef struct		s_queue
{
  bool			(*construct)(struct s_queue *queue);
  void			(*destruct)(struct s_queue *queue);
  bool			(*empty)(struct s_queue *queue);
  size_t		(*size)(struct s_queue *queue);
  void			*(*front)(struct s_queue *queue);
  void			*(*back)(struct s_queue *queue);
  void			(*push)(struct s_queue *queue, void *val);
  void			(*emplace)(struct s_queue *queue, void *val);
  void			(*pop)(struct s_queue *queue);
  t_queue_data		*data;
}			t_queue;

bool			queue_construct(t_queue *queue);
void			queue_destruct(t_queue *queue);
bool			queue_empty(t_queue *queue);
size_t			queue_size(t_queue *queue);
void			*queue_front(t_queue *queue);
void			*queue_back(t_queue *queue);
void			queue_push(t_queue *queue, void *val);
void			queue_emplace(t_queue *queue, void *val);
void			queue_pop(t_queue *queue);
