/*
** client_io.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server/src/core
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun  6 16:27:08 2017 Arthur Josso
** Last update Wed Jun 28 14:50:43 2017 Arthur Josso
*/

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include "core.h"

bool		write_on_client(t_client *client)
{
  char		buff[BUFF_SIZE + 1];
  size_t       	buff_len;
  ssize_t	write_ret;

  if (client->obuff[0] == '\0')
    return (true);
  buff[BUFF_SIZE] = '\0';
  buff_len = BUFF_SIZE;
  while (buff_len == BUFF_SIZE)
    {
      strncpy(buff, client->obuff, BUFF_SIZE);
      buff_len = strlen(buff);
      write_ret = send(client->fd, buff, buff_len, MSG_NOSIGNAL);
      if (write_ret == -1)
	{
	  if (errno != EPIPE && errno != ECONNRESET && errno != EINTR)
	    fat_err("write");
	  return (false);
	}
      strmove(client->obuff, client->obuff + write_ret);
    }
  return (true);
}

bool		read_on_client(t_client *client)
{
  char		buff[BUFF_SIZE + 1];
  ssize_t	read_ret;

  read_ret = BUFF_SIZE;
  while (read_ret == BUFF_SIZE)
    {
      read_ret = recv(client->fd, buff, BUFF_SIZE, 0);
      if (read_ret == -1)
	{
	  if (errno != EINTR)
	    fat_err("read");
	  return (false);
	}
      if (read_ret == 0)
	return (client_rm(client));
      buff[read_ret] = '\0';
      if (strlen(client->ibuff) < MAX_CMD_LENGTH)
	client->ibuff = cleaner_strcat(client->ibuff, buff);
    }
  return (true);
}
