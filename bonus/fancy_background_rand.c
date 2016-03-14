/*
** fancy_background_rand.c for bonu in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:09:55 2016 Iulian Rotaru
** Last update Sat Feb 20 11:35:46 2016 Iulian Rotaru
*/

#include "nusbo.h"

void			fancy_background_rand(t_bunny_pixelarray *pix)
{
  int			x[2];
  t_color		color[3];
  static int		round[3];
  unsigned int		base[3];

  x[1] = 0;
  increm_setter(&round[1], &round[0]);
  base[0] = rand() | BLACK;
  base[1] = rand() | BLACK;
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

void			disp_board(t_data *data)
{
  t_bunny_position	blit;
  int			i;
  int			y;

  y = 0;
  blit.y = 50;
  while (y < 4)
    {
      blit.x = (data->pix->clipable.clip_width
		- data->allum->clipable.clip_width) / 2
	- y * data->allum->clipable.clip_width;
      i = 0;
      while (i < y * 2  + 1)
	{
	  if (data->alum->plate[y][i] == true)
	    my_bunny_blit(data->pix, data->allum, &blit, 1);
	  else if (data->alum->plate[y][i] == 2)
	    my_bunny_blit(data->pix, data->allum_off, &blit, 1);
	  i++;
	  blit.x += data->allum->clipable.clip_width;
	}
      blit.y += data->allum->clipable.clip_height;
      y++;
    }
}

void			game_state(t_data *data)
{
  disp_board(data);
}

void			titler(t_data *data)
{
  t_text		text;

  text.x = 5;
  text.y = 7;
  text.police_size = 63;
  text.pos.x = 0;
  text.pos.y = 0;
  text.fg = WHITE;
  my_blitstr("Allum-1", data->pix, data->font, &text);

}

t_bunny_response	loop(void *info)
{
  t_data		*data;

  data = (t_data*)info;
  fancy_background(data->pix);
  titler(data);
  game_state(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}
