/*
** get_nb_matches_biggest.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:25:37 2016 Iulian Rotaru
** Last update Sat Feb 20 14:34:14 2016 Iulian Rotaru
*/

#include "allum.h"

int	get_nb_matches_biggest(t_alum *data)
{
  int	out;
  int	i;
  int	count;
  int	x;

  i = 0;
  out = 0;
  x = 0;
  while (i < data->nb_lines)
    {
      count = 0;
      x = 0;
      while (x < i * 2 + data->nb_width)
	{
	  if (data->plate[i][x] == true)
	    count++;
	  x++;
	}
      if (count > out)
	out = count;
      i++;
    }
  return (out);
}

int	how_many_one(t_alum *data)
{
  int	out;
  int	i;
  int	count;
  int	y;

  i = 0;
  out = 0;
  count = 0;
  while (i < data->nb_lines)
    {
      y = 0;
      count = 0;
      while (y < i * 2 + data->nb_width)
	{
	  if (data->plate[i][y] == true)
	    count++;
	  y++;
	}
      if (count == 1)
	out += 1;
      i++;
    }
  return (out);
}

int	how_many_remain(int *combo, t_alum *data)
{
  int	i;
  int	out;

  i = 0;
  out = 0;
  while (i < (combo[0] - 1) * 2 + data->nb_width)
    {
      if (data->plate[combo[0] - 1][i] == true)
	out++;
      i++;
    }
  return (out);
}

int	add_one(t_alum *data, int line)
{
  int	x;

  x = 0;
  while (data->plate[line - 1][x] == true)
    x++;
  data->plate[line - 1][x] = true;
  return (0);
}

int	ai_message(int matches, int line)
{
  my_putstr("AI removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putstr("\n");
  return (0);
}
