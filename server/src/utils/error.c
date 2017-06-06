/*
** misc.c for lol in /home/tetra/rendu/psu/PSU_2016_myftp
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 29 20:45:45 2017 Arthur Josso
** Last update Sat Jun  3 19:30:19 2017 Arthur Josso
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void	fat_err(const char *msg)
{
  fprintf(stderr, "ERROR: %s: %s\n", msg, strerror(errno));
  exit(1);
}

void	fat_err_custom(const char *msg)
{
  fprintf(stderr, "ERROR: %s\n", msg);
  exit(1);
}
