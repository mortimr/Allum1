/*
** selected.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:11:48 2016 Iulian Rotaru
** Last update Sat Feb 20 11:44:27 2016 Iulian Rotaru
*/

#include "nusbo.h"

int			selected(t_alum *data)
{
  int			x;
  int			y;

  y = 0;
  while (y < 4)
    {
      x = 0;
      while (x < y * 2 + 1)
	{
	  if (data->plate[y][x] == 2)
	    return (y);
	  x++;
	}
      y++;
    }
  return (5);
}

void			check_click(t_bunny_position *pos,
				    int *x,
				    t_data *data)
{
  if ((bunny_get_mouse_position()->x >
       pos->x && bunny_get_mouse_position()->x <
       pos->x + data->allum->clipable.clip_width)
      && (bunny_get_mouse_position()->y >
	  pos->y && bunny_get_mouse_position()->y <
	  pos->y + data->allum->clipable.clip_height))
    {
      if (data->alum->plate[x[1]][x[0]] == true &&
	  ((selected(data->alum) == x[1]) ||
	   (selected(data->alum) == 5)))
	data->alum->plate[x[1]][x[0]] = 2;
      else if (data->alum->plate[x[1]][x[0]] == 2)
	data->alum->plate[x[1]][x[0]] = true;
    }
}

t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton button,
			      void *info)
{
  int			x[2];
  t_bunny_position	pos;
  t_data		*data;

  data = (t_data*)info;
  x[1] = 0;
  pos.y = 50;
  while (x[1] < 4 && state == GO_DOWN && button == BMB_LEFT)
    {
      x[0] = 0;
      pos.x = (data->pix->clipable.clip_width
	      - data->allum->clipable.clip_width) / 2
	- x[1] * data->allum->clipable.clip_width;
      while (x[0] < x[1] * 2 + 1)
	{
	  check_click(&pos, x, data);
	  x[0]++;
	  pos.x += data->allum->clipable.clip_width;
	}
      x[1]++;
      pos.y += data->allum->clipable.clip_height;
    }
  return (GO_ON);
}

int	matches_left(t_alum *data)
{
  int	x;
  int	y;
  int	count;

  y = 0;
  count = 0;
  while (y < 4)
    {
      x = 0;
      while (x < y * 2 + 1)
	{
	  if (data->plate[y][x] == true)
	    count++;
	  x++;
	}
      y++;
    }
  return (count);
}

void	prepare_first_text(t_text *text)
{
  text->police_size = 63;
  text->x = 5;
  text->y = 7;
  text->pos.x = rand() % (1700);
  text->pos.y = rand() % (1000);
  text->fg = 0xFF000000;
}
