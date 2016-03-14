/*
** setuper.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:23:21 2016 Iulian Rotaru
** Last update Thu Feb 18 20:00:38 2016 Iulian Rotaru
*/

#include "allum.h"

void	setuper(char *say, t_alum *data)
{
  put_plate(data);
  my_putchar('\n');
  my_putstr(say);
  play_turn(data);
}

void	versus_main_loop(int *i, t_alum *data, int j)
{
  if (data->nb_lives > 1)
    {
      my_putstr("\nRound ");
      my_put_nbr(j);
      my_putstr("\n");
    }
  set_board(data);
  while (data->winner == 0)
    {
      if (live(data) == 1)
	data->winner = - 1;
      else
	setuper("Player one's turn :\n", data);
      if (live(data) == 1)
	data->winner = 1;
      else
	setuper("Player two's turn :\n", data);
    }
  if (data->winner == - 1)
    i[0]--;
  else
    i[1]--;
  data->winner = 0;
}

int	versus_version(t_alum *data)
{
  int	i[2];
  int	j;

  j = 1;
  i[0] = data->nb_lives;
  i[1] = data->nb_lives;
  while (i[0] > 0 && i[1] > 0)
    {
      versus_main_loop(i, data, j);
      j++;
    }
  put_plate(data);
  if (i[0] == 0)
    my_putstr("Player 2 Won !\n");
  else
    my_putstr("Player 1 Won !\n");
  return (0);
}

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
