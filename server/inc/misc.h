/*
** misc.h for lol in /home/tetra/rendu/psu/PSU_2016_ftrace
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 20 20:19:40 2017 Arthur Josso
** Last update Tue Jun 20 20:04:58 2017 Arthur Josso
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/*
** Allocation 
*/

void	*xmalloc(size_t size);
void	*xrealloc(void *ptr, size_t size);

/*
** Error
*/

void	fat_err(const char *msg);
void	fat_err_custom(const char *msg);

/*
** String
*/

void	strmove(char *dest, const char *src);
void	strcapitalize(char *s);

/*
** Checker
*/

bool	is_nbr(const char *s);

/*
** Math
*/

#define GET_DIST(xa, ya, xb, yb)	(pow(xa - xb, 2) + pow(ya - yb, 2))

int	umod(int a, int b);
