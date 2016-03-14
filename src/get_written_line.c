/*
** get_written_line.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:22:39 2016 Iulian Rotaru
** Last update Sun Feb 21 21:43:18 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "allum.h"

int	get_written_line(int *matches, int *line, t_alum *data)
{
  int	done;
  char	*s;

  done = 0;
  while (done == 0)
    {
      my_putstr("Line: ");
      if ((s = get_term_line()) == NULL)
	return (- 1);
      if ((*line = check_line_error(s, data, *line)) != - 1)
	done = 1;
    }
  return (get_written_matches(matches, data, line));
}

int	get_written_matches(int *matches, t_alum *data, int *line)
{
  int	done;
  char	*s;

  done = 0;
  while (done == 0)
    {
      my_putstr("Matches: ");
      if ((s = get_term_line()) == NULL)
	return (- 1);
      if ((*matches =
	   check_matches_error(s, data, line[0], *matches)) == - 1)
	{
	  return (get_written_line(matches, line, data));
	}
      else
	done = 1;
    }
  return (0);
}

int	play_turn(t_alum *data)
{
  int	line;
  int	matches;

  if (get_written_line(&matches, &line, data) == - 1)
    return (- 1);
  take_off(data, line ,matches);
  my_putstr("Player removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  my_putstr("\n");
  return (0);
}

int	live(t_alum *data)
{
  int	x;
  int	y;

  y = 0;
  while (y < data->nb_lines)
    {
      x = 0;
      while (x < y * 2 + data->nb_width)
	{
	  if (data->plate[y][x] == true)
	    return (0);
	  x++;
	}
      y++;
    }
  return (1);
}

void	set_board(t_alum *data)
{
  int	x;
  int	y;

  y = 0;
  while (y < data->nb_lines)
    {
      x = 0;
      while (x < y * 2 + data->nb_width)
	{
	  data->plate[y][x] = true;
	  x++;
	}
      y++;
    }
}
