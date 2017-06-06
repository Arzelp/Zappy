/*
** misc.h for lol in /home/tetra/rendu/psu/PSU_2016_ftrace
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 20 20:19:40 2017 Arthur Josso
** Last update Tue Jun  6 14:43:01 2017 Arthur Josso
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

void	*xmalloc(size_t size);
void	*xrealloc(void *ptr, size_t size);

void	fat_err(const char *msg);
void	fat_err_custom(const char *msg);

void	strmove(char *dest, const char *src);
void	strcapitalize(char *s);
