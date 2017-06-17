/*
** utils.h for utils in /client/inc/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 11:11:42 2017 Frederic Oddou
** Last update Sat Jun 17 22:14:44 2017 Frederic Oddou
*/

#pragma once

#include "core.h"

bool		is_nbr(const char *s);
bool		is_answer_ok(const char *s);
bool		is_answer_ko(const char *s);

char		*strtok_single(char *str, char const *delims);

char		*trim(char *str);

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
