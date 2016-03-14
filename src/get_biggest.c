/*
** get_biggest.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:24:06 2016 Iulian Rotaru
** Last update Thu Feb 18 20:08:07 2016 Iulian Rotaru
*/

#include "allum.h"

int	get_biggest(t_alum *data, int mode)
{
  int	x[2];
  int	count;
  int	out[2];

  x[0] = 0;
  out[0] = 1;
  out[1] = 0;
  while (x[0] < data->nb_lines)
    {
      x[1] = 0;
      count = 0;
      while (x[1] < data->nb_width + x[0] * 2)
	{
	  if (data->plate[x[0]][x[1]] == true)
	    count++;
	  x[1]++;
	}
      if (count > out[1])
	{
	  out[0] = x[0] + 1;
	  out[1] = count;
	}
      x[0]++;
    }
  return (out[mode]);
}

int	get_smallest(t_alum *data, int mode)
{
  int	x[2];
  int	count;
  int	out[2];

  x[0] = 0;
  out[0] = 1;
  out[1] = data->nb_width + data->nb_lines * 2;
  while (x[0] < data->nb_lines)
    {
      x[1] = 0;
      count = 0;
      while (x[1] < data->nb_width + x[0] * 2)
	{
	  if (data->plate[x[0]][x[1]] == true)
	    count++;
	  x[1]++;
	}
      if (count <= out[1] && count > 0)
	{
	  out[0] = x[0] + 1;
	  out[1] = count;
	}
      x[0]++;
    }
  return (out[mode]);
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
