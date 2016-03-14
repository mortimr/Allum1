/*
** fill_text_one.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:12:55 2016 Iulian Rotaru
** Last update Sat Feb 20 11:36:44 2016 Iulian Rotaru
*/

#include "nusbo.h"

void				fill_text_one(t_text *text, int i)
{
  text->police_size = 63;
  text->x = 5;
  text->y = 7;
  text->pos.x = rand() % (1700);
  text->pos.y = rand() % (1000);
  text->fg = 0xFF000000 + 0x00010101 * i;
}

void				dany_part_ani(t_data *data, int i)
{
  static t_bunny_position	dany;

  if (data->alum->dany == 1)
    {
      if (i % 10 == 0)
	{
	  dany.x = rand() %
	    (data->pix->clipable.clip_width
	     - data->lol->clipable.clip_width);
	  dany.y = rand() %
	    (data->pix->clipable.clip_height
	     - data->lol->clipable.clip_height);
	}
      if (i % 20 < 10)
	bunny_blit(&data->win->buffer, &data->lol->clipable, &dany);
    }
}

void				loser_animation(t_data *data)
{
  t_text			text[255];
  int				i;
  int				y;

  i = 1;
  prepare_first_text(&text[0]);
  while (i < 255)
    {
      y = 0;
      fancy_background_rand(data->pix);
      while (y < i)
	{
	  my_blitstr("LOSER", data->pix, data->font, &text[y]);
	  y++;
	}
      fill_text_one(&text[i], i);
      i++;
      bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
      dany_part_ani(data, i);
      bunny_display(data->win);
    }
}

int				update_plate(t_data *data)
{
  int				x;
  int				y;

  if (selected(data->alum) != 5)
    {
      y = 0;
      while (y < 4)
	{
	  x = 0;
	  while (x < y * 2 + 1)
	    {
	      if (data->alum->plate[y][x] == 2)
		data->alum->plate[y][x] = 0;
	      x++;
	    }
	  y++;
	}
      if (matches_left(data->alum) == 0)
	{
	  loser_animation(data);
	  return (1);
	}
      ai_turn(data->alum);
    }
  return (0);
}

t_bunny_response		key(t_bunny_event_state state,
				    t_bunny_keysym sym,
				    void *info)
{
  t_data			*data;

  data = (t_data*)info;
  if (state == GO_DOWN && sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && sym == BKS_RETURN)
    if (update_plate(data) == 1)
      return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
