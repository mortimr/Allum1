/*
** ai_turn.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:26:23 2016 Iulian Rotaru
** Last update Sun Feb 21 21:58:18 2016 Iulian Rotaru
*/

#include "allum.h"

int	ai_turn(t_alum *data)
{
  int	*combo;
  int	biggest;
  int	one[2];

  if ((combo = find_best_combo(data)) == NULL)
    return (- 1);
    take_off(data, combo[0], combo[1]);
  if ((biggest = get_nb_matches_biggest(data)) < 2)
    {
      one[0] = how_many_one(data);
      if (one[0] % 2 == 0)
	{
	  if ((one[1] = how_many_remain(combo, data)) == 0)
	    {
	      add_one(data, combo[0]);
	      combo[1] -= 1;
	    }
	  else if (one[1] == 1)
	    {
	      take_off(data, combo[0], 1);
	      combo[1] += 1;
	    }
	}
    }
  return (ai_message(combo[1], combo[0]));
}

int	ai_setuper(char *say, t_alum *data)
{
  my_putchar('\n');
  my_putstr(say);
  if (ai_turn(data) == - 1)
    return (- 1);
  put_plate(data);
  return (0);
}

int	ai_human_setuper(char *say, t_alum *data)
{
  my_putchar('\n');
  my_putstr(say);
  if (play_turn(data) == - 1)
    return (- 1);
  put_plate(data);
  return (0);
}

int	ai_loop(int *i, int j, t_alum *data)
{
  set_board(data);
  if (data->nb_lives > 1)
    {
      my_putstr("Round ");
      my_put_nbr(j);
      my_putstr("\n");
      put_plate(data);
    }
  while (data->winner == 0)
    {
      if (ai_loop_next(data) == - 1)
	return (- 1);
    }
  if (data->winner == - 1)
    i[0]--;
  else
    i[1]--;
  data->winner = 0;
  return (0);
}

int	ai_version(t_alum *data)
{
  int	i[2];
  int	j;

  j = 1;
  i[0] = data->nb_lives;
  i[1] = data->nb_lives;
  if (data->nb_lives == 1)
    put_plate(data);
  while (i[0] > 0 && i[1] > 0)
    {
      if (ai_loop(i, j, data) == - 1)
	return (- 1);
      j++;
    }
  if (i[1] == 0)
    my_putstr("I lost.. snif.. but I’ll get you next time!!\n");
  else
    my_putstr("You lost, too bad..\n");
  return (0);
}
