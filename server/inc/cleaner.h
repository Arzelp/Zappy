/*
** cleaner.h for lol in /home/tetra/rendu/psu/PSU_2016_myirc
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon May 22 17:46:11 2017 Arthur Josso
** Last update Tue Jun  6 15:39:31 2017 Arthur Josso
*/

#pragma once

void	cleaner_func();

void	cleaner_add_addr(void *addr);
void	cleaner_add_fd(int fd);

void	cleaner_rm_fd(int fd);
void	cleaner_rm_addr(void *addr);

void    *cleaner_resize_container(void *ptr, size_t *max, size_t size);

extern void	**addrs;
extern size_t	nbr_addrs;

/*
** Utils
*/

char	*cleaner_strcat(char *dest, const char *src);
void	*cleaner_realloc(void *ptr, size_t size);
void	*cleaner_malloc(size_t size);
