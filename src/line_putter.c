/*
** line_putter.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:21:04 2016 Iulian Rotaru
** Last update Thu Feb 18 20:05:45 2016 Iulian Rotaru
*/

#include "allum.h"

void	line_putter(t_alum *data)
{
  int	x;

  x = 0;
  while (x < 2 + (data->nb_lines * 2) + (data->nb_width - 2))
    {
      my_putchar('*');
      x++;
    }
}

void	space_putter(t_alum *data, int x)
{
  int	y;

  y = 0;
  while (y < data->nb_lines - x - 1)
    {
      my_putchar(' ');
      y++;
    }
}

void	matches_putter(t_alum *data, int x)
{
  int	y;

  y = 0;
  while (y < data->nb_width + x * 2)
    {
      if (data->plate[x][y] == true)
	my_putchar('|');
      else
	my_putchar(' ');
      y++;
    }
}

void	put_plate(t_alum *data)
{
  int	x;

  line_putter(data);
  my_putchar('\n');
  x = 0;
  while (x < data->nb_lines)
    {
      my_putchar('*');
      space_putter(data, x);
      matches_putter(data, x);
      space_putter(data, x);
      my_putchar('*');
      my_putchar('\n');
      x++;
    }
  line_putter(data);
  my_putchar('\n');
}

int	check_if_line_empty(t_alum *data, int line)
{
  int	x;
  int	count;

  x = 0;
  count = 0;
  while (x < data->nb_width + (line - 1) * 2)
    {
      if (data->plate[line - 1][x] == true)
	count++;
      x++;
    }
  return (count);
}
