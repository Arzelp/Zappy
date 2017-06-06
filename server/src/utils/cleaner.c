/*
** fini.c for lol in /home/tetra/rendu/psu/PSU_2016_myftp
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed May 10 11:08:14 2017 Arthur Josso
** Last update Tue Jun  6 17:19:28 2017 Arthur Josso
*/

#include <stdlib.h>
#include <unistd.h>
#include "misc.h"
#include "cleaner.h"

static int	*fds = NULL;
static size_t	nbr_fds = 0;
static size_t	max_fds = 0;

void		**addrs = NULL;
size_t		nbr_addrs = 0;
static size_t	max_addrs = 0;

void	cleaner_add_fd(int fd)
{
  if (nbr_fds == max_fds)
    fds = cleaner_resize_container(fds, &max_fds, sizeof(int));
  fds[nbr_fds] = fd;
  nbr_fds++;
}

void	cleaner_add_addr(void *addr)
{
  if (nbr_addrs == max_addrs)
    addrs = cleaner_resize_container(addrs, &max_addrs, sizeof(void*));
  addrs[nbr_addrs] = addr;
  nbr_addrs++;
}

void		cleaner_func()
{
  size_t	i;

  i = 0;
  while (i < nbr_fds)
    close(fds[i++]);
  if (fds)
    free(fds);
  i = 0;
  while	(i < nbr_addrs)
    free(addrs[i++]);
  if (addrs)
    free(addrs);
}

void		cleaner_rm_fd(int fd)
{
  size_t	i;

  if (fd == -1)
    return;
  close(fd);
  i = 0;
  while (i < nbr_fds)
    {
      if (fds[i] == fd)
	{
	  nbr_fds--;
	  fds[i] = fds[nbr_fds];
	  return;
	}
      i++;
    }
}

void		cleaner_rm_addr(void *addr)
{
  size_t	i;

  if (addr == NULL)
    return;
  free(addr);
  i = 0;
  while (i < nbr_addrs)
    {
      if (addrs[i] == addr)
        {
          nbr_addrs--;
          addrs[i] = addrs[nbr_addrs];
          return;
        }
      i++;
    }
}
