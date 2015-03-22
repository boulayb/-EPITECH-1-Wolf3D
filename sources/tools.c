/*
** tools.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d/sources
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Tue Dec 30 11:38:25 2014 arnaud boulay
** Last update Tue Dec 30 11:42:53 2014 arnaud boulay
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}
