/*
** make_tab.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:06:07 2016 Iulian Rotaru
** Last update Sun Feb 21 21:53:13 2016 Iulian Rotaru
*/

#include "nusbo.h"

int	*get_tab(t_alum *data)
{
  int	*tab;
  int	i;
  int	count;
  int	y;

  if ((tab = malloc(sizeof(int) * data->nb_lines)) == NULL)
    return (NULL);
  i = 0;
  while (i < data->nb_lines)
    {
      count = 0;
      y = 0;
      while (y < i * 2 + data->nb_width)
	{
	  if (data->plate[i][y] == true)
	    count++;
	  y++;
	}
      tab[i] = count;
      i++;
    }
  return (tab);
}

int	*more_than_two(t_alum *data, int *tab, int *out)
{
  int	end_xor;
  int	tmp_xor;
  int	i;

  i = 1;
  tmp_xor = tab[0];
  while (i < data->nb_lines)
    {
      tmp_xor = tmp_xor ^ tab[i];
      i++;
    }
  end_xor = tmp_xor;
  i = 0;
  while (i < data->nb_lines)
    {
      if ((tab[i] ^ end_xor) < tab[i])
	{
	  out[0] = i + 1;
	  out[1] = tab[i] - (tab[i] ^ end_xor);
	  free(tab);
	  return (out);
	}
      i++;
    }
  return (out);
}

int	*two_only(t_alum *data, int *tab, int *out)
{
  int	small;
  int	big;

  small = find_small(tab, data);
  big = find_bigger(tab, data);
  out[0] = big + 1;
  out[1] = tab[big] - tab[small];
  free(tab);
  return (out);
}

int	*one_only(t_alum *data, int *tab, int *out)
{
  int	big;

  big = find_bigger(tab, data);
  out[0] = big + 1;
  out[1] = tab[big] - 1;
  free(tab);
  return (out);
}

int	*find_best_combo(t_alum *data)
{
  int	*tab;
  int	*out;

  if ((out = malloc(sizeof(int) * 2)) == NULL)
    return (NULL);
  tab = get_tab(data);
  if (nb_heaps(tab, data) > 2)
    return (more_than_two(data, tab, out));
  else if (nb_heaps(tab,data) == 2)
    return (two_only(data, tab, out));
  else if (nb_heaps(tab,data) == 1)
    return (one_only(data, tab, out));
  return (NULL);
}
