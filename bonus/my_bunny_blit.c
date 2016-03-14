/*
** my_bunny_blit.c for liblap in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  2 13:43:37 2016 Iulian Rotaru
** Last update Sat Feb 20 14:44:45 2016 Iulian Rotaru
*/

#include <lapin.h>

unsigned int		get_mix_color(t_bunny_pixelarray *pix,
				      int idx,
				      unsigned int color)
{
  t_color		one;
  t_color		two;
  t_color		res;
  unsigned int		*ptr;
  double		coeff;

  ptr = (unsigned int*)pix->pixels;
  one.full = color;
  two.full = ptr[idx];
  coeff = (double) two.argb[3] / 256.0;
  res.argb[3] = two.argb[3] * coeff + one.argb[3] * (1 - coeff);
  res.argb[2] = two.argb[2] * coeff + one.argb[2] * (1 - coeff);
  res.argb[1] = two.argb[1] * coeff + one.argb[1] * (1 - coeff);
  res.argb[0] = two.argb[0] * coeff + one.argb[0] * (1 - coeff);
  return (res.full);
}

void			set_default_pos(t_bunny_position *place,
					t_bunny_position *pos)
{
  if (pos == NULL)
    {
      place->x = 0;
      place->y = 0;
    }
  else
    {
      place->x = pos->x;
      place->y = pos->y;
    }
}

void			my_bunny_blit(t_bunny_pixelarray *big,
				      t_bunny_pixelarray *small,
				      t_bunny_position *pos,
				      int mode)
{
  t_bunny_position	place;
  int			x;
  int			y;
  unsigned int		*ptr;

  (void) mode;
  ptr = (unsigned int*)big->pixels;
  set_default_pos(&place, pos);
  y = 0;
  while (y < small->clipable.clip_height)
    {
      x = 0;
      while (x < small->clipable.clip_width)
	{
	  ptr[(place.y + y) * big->clipable.clip_width + x + place.x]
	    = get_mix_color(small, (y * small->clipable.clip_width) + x,
			    ptr[(place.y + y) * big->clipable.clip_width
				+ x + place.x]);
	  x++;
	}
      y++;
    }
}
