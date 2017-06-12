/*
** entity_tool.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jun 12 22:19:16 2017 Arthur Josso
** Last update Mon Jun 12 22:54:12 2017 Arthur Josso
*/

#include <string.h>
#include "core.h"

static char	*split_arg_from_cmd(char *raw)
{
  char	*cmd;

  cmd = strchr(raw, ' ');
  if (cmd == NULL)
    return (strchr(raw, '\0'));
  *cmd = '\0';
  do
    cmd++;
  while (*cmd == ' ');
 return (cmd);
}

bool	exec_entity_cmd(const t_entity_cmd *cmds, void *entity,
			t_cmd_type bad_cmd)
{
  char	*cmd;
  char	*arg;
  int	i;

  while ((cmd = recv_cmd()) != NULL)
    {
      i = 0;
      arg = split_arg_from_cmd(cmd);
      while (cmds[i].name && strcmp(cmds[i].name, cmd) != 0)
	i++;
      if (cmds[i].name == NULL)
	send_cmd(bad_cmd);
      else
	cmds[i].func(entity, arg);
      cleaner_rm_addr(cmd);
    }
  return (true);
}
