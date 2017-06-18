/*
** utils.h for utils in /client/inc/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 11:11:42 2017 Frederic Oddou
** Last update Sun Jun 18 20:49:11 2017 Frederic Oddou
*/

#pragma once

#include "core.h"

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
  enum e_obj	obj_id;
  const char	*name;
}		t_get_objects_type;

const char	*get_object_name_from_type(enum e_obj obj_id);
enum e_obj	get_object_id_from_name(const char *name);

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
