/*
** make_plate.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:04:22 2016 Iulian Rotaru
** Last update Sat Feb 20 11:26:11 2016 Iulian Rotaru
*/

#include "nusbo.h"

int	make_plate(t_alum *data)
{
  int	i;
  int	increm;
  int	x;

  if ((data->plate = malloc(sizeof(int*) * data->nb_lines)) == NULL)
    return (- 1);
  i = 0;
  increm = data->nb_width;
  while (i < data->nb_lines)
    {
      x = 0;
      if ((data->plate[i] = malloc(sizeof(int) * increm)) == NULL)
	return (- 1);
      while (x < increm)
	{
	  data->plate[i][x] = true;
	  x++;
	}
      i++;
      increm += 2;
    }
  return (0);
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

int	live(t_alum *data)
{
  int	x;
  int	y;

  y = 0;
  while (y < data->nb_lines)
    {
      x = 0;
      while (x < y * 2 + data->nb_width)
	{
	  if (data->plate[y][x] == true)
	    return (0);
	  x++;
	}
      y++;
    }
  return (1);
}

void	set_board(t_alum *data)
{
  int	x;
  int	y;

  y = 0;
  while (y < data->nb_lines)
    {
      x = 0;
      while (x < y * 2 + data->nb_width)
	{
	  data->plate[y][x] = true;
	  x++;
	}
      y++;
    }
}
