/*
** math.c for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jun 20 17:49:03 2017 Arthur Josso
** Last update Tue Jun 20 17:55:04 2017 Arthur Josso
*/

int	umod(int a, int b)
{
  a %= b;
  return (a < 0 ? a + b : a);
}
