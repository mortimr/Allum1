/*
** check_line_error_next.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:21:50 2016 Iulian Rotaru
** Last update Sat Feb 20 08:49:28 2016 Iulian Rotaru
*/

#include "allum.h"

int	check_line_error_next(t_alum *data, int line)
{
  if (line < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (- 1);
    }
  if (check_if_line_empty(data, line) == 0)
    {
      my_putstr("Error: this line is empty\n");
      return (- 1);
    }
  return (line);
}

int	check_line_error(char *getter, t_alum *data, int line)
{
  if (is_it_num(getter) == 1 || !my_strlen(getter))
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (- 1);
    }
  line = my_getnbr(getter);
  if (line == 0)
    {
      my_putstr("Error: this line is out of range\n");
      return (- 1);
    }
  if (line > data->nb_lines)
    {
      my_putstr("Error: this line is out of range\n");
      return (- 1);
    }
  return (check_line_error_next(data, line));
}

int	check_matches_error_next(t_alum *data, int line, int matches)
{
  int	x;
  int	count;

  x = 0;
  count = 0;
  while (count < matches && x < (line - 1) * 2 + data->nb_width)
    {
      if (data->plate[line - 1][x] == true)
	count++;
      x++;
    }
  if (count < matches)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (- 1);
    }
  return (matches);
}

int	check_matches_error(char *getter, t_alum *data, int line, int matches)
{
  if (is_it_num(getter) == 1 || !my_strlen(getter))
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      return (- 1);
    }
  matches = my_getnbr(getter);
  if (matches <= 0)
    {
      if (matches < 0)
	my_putstr("Error: invalid input (positive number expected)\n");
      if (matches == 0)
	my_putstr("Error: you have to remove at least one match\n");
      return (- 1);
    }
  if ((line - 1) * 2 + data->nb_width < matches)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (- 1);
    }
  return (check_matches_error_next(data, line, matches));
}

void	take_off(t_alum *data, int line, int matches)
{
  int	x;
  int	count;

  count = 0;
  x = (line - 1) * 2 + data->nb_width - 1;
  while (count < matches)
    {
      if (data->plate[line - 1][x] == true)
	{
	  count++;
	  data->plate[line - 1][x] = false;
	}
      x--;
    }
}
