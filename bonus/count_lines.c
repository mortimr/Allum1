/*
** count_lines.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:05:16 2016 Iulian Rotaru
** Last update Sat Feb 20 11:29:12 2016 Iulian Rotaru
*/

#include "nusbo.h"

int	count_lines(t_alum *data)
{
  int	x;
  int	y;
  int	count;
  int	k;

  y = 0;
  count = 0;
  while (y < data->nb_lines)
    {
      k = 0;
      x = 0;
      while (x < data->nb_width + y * 2)
	{
	  if (k == 0 && data->plate[y][x] == true)
	    {
	      count++;
	      k = 1;
	    }
	  x++;
	}
      y++;
    }
  return (count);
}

int	count_matches(t_alum *data)
{
  int	x;
  int	y;
  int	count;

  y = 0;
  count = 0;
  while (y < data->nb_lines)
    {
      x = 0;
      while (x < data->nb_width + y * 2)
	{
	  if (data->plate[y][x] == true)
	    count++;
	  x++;
	}
      y++;
    }
  return (count);
}

int	nb_heaps(int *tab, t_alum *data)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (i < data->nb_lines)
    {
      if (tab[i] > 0)
	count++;
      i++;
    }
  return (count);
}

int	find_small(int *tab, t_alum *data)
{
  int	i;
  int	out;

  i = 0;
  out = 1000;
  while (i < data->nb_lines)
    {
      if (out > tab[i] && tab[i] > 0)
	out = tab[i];
      i++;
    }
  i = 0;
  while (i < data->nb_lines)
    {
      if (out == tab[i])
	return (i);
      i++;
    }
  return (out);
}

int	find_bigger(int *tab, t_alum *data)
{
  int	i;
  int	out;

  i = 0;
  out = 0;
  while (i < data->nb_lines)
    {
      if (out < tab[i] && tab[i] > 0)
	out = tab[i];
      i++;
    }
  i = 0;
  while (i < data->nb_lines)
    {
      if (out == tab[i])
	return (i);
      i++;
    }
  return (out);
}
