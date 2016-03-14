/*
** ai_turn.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:08:53 2016 Iulian Rotaru
** Last update Sun Feb 21 21:52:49 2016 Iulian Rotaru
*/

#include "nusbo.h"

int		ai_turn(t_alum *data)
{
  int		*combo;
  int		biggest;
  int		one;

  if ((combo = find_best_combo(data)) == NULL)
    return (- 1);
  take_off(data, combo[0], combo[1]);
  if ((biggest = get_nb_matches_biggest(data)) < 2)
    {
      one = how_many_one(data);
      if (one % 2 == 0)
	pair_way(data, combo);
    }
  free(combo);
  return (0);
}

void		fancy_background(t_bunny_pixelarray *pix)
{
  int		x[2];
  t_color	color[3];
  static int	round[3];
  unsigned int	base[3];

  x[1] = 0;
  increm_setter(&round[1], &round[0]);
  base[0] = 0xFF101010;
  base[1] = 0xFF202020;
  round[2] = 0;
  while (x[1] < pix->clipable.clip_height)
    {
      color[0].full = base[0];
      color[1].full = base[1];
      x[0] = 0;
      bg_loop(x, pix, round, color);
      bg_loop_next(round, base);
      x[1]++;
    }
  round[0] += round[1];
}

void		increm_setter(int *increm, int *round)
{
  if (*round == 0)
    *round = 20;
  if (*round == 300)
    *increm = - 1;
  if (*round == 20)
    *increm = 1;
}

void		bg_loop(int *x,
			t_bunny_pixelarray *pix,
			int *round,
			t_color *color)
{
  while (x[0] < pix->clipable.clip_width)
    {
      if (x[0] == 0)
	round[2]++;
      if (x[0] % round[0] == 0)
	{
	  color[2].full = color[1].full;
	  color[1].full = color[0].full;
	  color[0].full = color[2].full;
	}
      if (x[1] >= 0 && x[0] >= 0)
	((unsigned int*)pix->pixels)
	  [x[1] * pix->clipable.clip_width + x[0]] = color[0].full;
      x[0]++;
    }
}

void		bg_loop_next(int *round, unsigned int *base)
{
  if (round[2] == round[0] - 1)
    {
      round[2] = 0;
      base[2] = base[1];
      base[1] = base[0];
      base[0] = base[2];
    }
}
