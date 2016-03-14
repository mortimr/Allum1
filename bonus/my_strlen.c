/*
** my_strlen.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:01:21 2016 Iulian Rotaru
** Last update Sat Feb 20 11:31:14 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "nusbo.h"

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
  data->dany = 0;
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}
