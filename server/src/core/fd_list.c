/*
** fd_list.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server/src/core
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:27:21 2017 Arthur Josso
** Last update Tue Jun  6 16:27:21 2017 Arthur Josso
*/

#include <poll.h>
#include <string.h>
#include "core.h"

static t_poll *fds = NULL;
static nfds_t nb_fds = 0;

t_poll	*fd_list_get()
{
  return (fds);
}

nfds_t	fd_list_get_nb()
{
  return (nb_fds);
}

void		fd_list_add(int fd)
{
  size_t	i;
  t_poll	*tmp;

  cleaner_add_fd(fd);
  i = 0;
  while (i < nb_fds)
    {
      if (fds[i].fd == -1)
	{
	  fds[i].fd = fd;
	  return;
	}
      i++;
    }
  tmp = xmalloc(sizeof(t_poll) * (nb_fds + 1));
  memcpy(tmp, fds, sizeof(t_poll) * nb_fds);
  if (fds)
    cleaner_rm_addr(fds);
  fds = tmp;
  cleaner_add_addr(fds);
  fds[nb_fds].fd = fd;
  fds[nb_fds].events = POLLIN | POLLOUT;
  fds[nb_fds].revents = 0;
  nb_fds++;
}

void		fd_list_rm(int fd)
{
  size_t	i;

  cleaner_rm_fd(fd);
  i = 0;
  while (i < nb_fds)
    {
      if (fds[i].fd == fd)
	{
	  fds[i].fd = -1;
	  return;
	}
      i++;
    }
}

short		fd_list_get_revents(int fd)
{
  size_t        i;

  i = 0;
  while (i < nb_fds)
    {
      if (fds[i].fd == fd)
	return (fds[i].revents);
      i++;
    }
  return (0);
}
