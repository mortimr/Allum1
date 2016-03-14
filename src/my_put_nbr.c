/*
** my_put_nbr.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:12:30 2016 Iulian Rotaru
** Last update Thu Feb 18 20:10:16 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "allum.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    nb = - nb;
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_getnbr(const char *nb)
{
  int	multi;
  int	out;
  int	i;

  i = my_strlen(nb) - 1;
  multi = 1;
  out = 0;
  while (i >= 0)
    {
      if (nb[i] >= '0' && nb[i] <= '9')
	out += (nb[i] - 48) * multi;
      if (nb[i] == '-')
	out = - out;
      multi *= 10;
      i--;
    }
  return (out);
}

void	set_zero(t_alum *data)
{
  data->winner = 0;
  data->human = 0;
  data->lives = 0;
  data->lines = 0;
  data->width = 0;
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
