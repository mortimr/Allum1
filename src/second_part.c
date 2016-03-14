/*
** second_part.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:20:15 2016 Iulian Rotaru
** Last update Sat Feb 20 14:36:16 2016 Iulian Rotaru
*/

#include "allum.h"

int	second_part(char **argv, t_alum *data, int i)
{
  if (my_strcmp("-w", argv[i]) == 0)
    {
      data->width = 1;
      if (argv[i + 1] == NULL)
	return (print_help(- 1));
      if (is_it_num(argv[i + 1]) == 1)
	return (print_help(- 1));
      if (((data->nb_width = my_getnbr(argv[i + 1])) <= 0) ||
	  ((data->nb_width = my_getnbr(argv[i + 1])) > 10))
	return (print_help(- 1));
    }
  return (third_part(argv, data, i));
}

int	first_part(char **argv, t_alum *data, int i)
{
  if (my_strcmp("-l", argv[i]) == 0)
    {
      data->lives = 1;
      if (argv[i + 1] == NULL)
	return (print_help(- 1));
      if (is_it_num(argv[i + 1]) == 1)
	return (print_help(- 1));
      if ((data->nb_lives = my_getnbr(argv[i + 1])) <= 0)
	return (print_help(- 1));
    }
  return (second_part(argv, data, i));
}

void	fill_with_default(t_alum *data)
{
  if (data->lives == 0)
    data->nb_lives = 1;
  if (data->width == 0)
    data->nb_width = 1;
  if (data->lines == 0)
    data->nb_lines = 4;
}

int	check_argv(int argc, char **argv, t_alum *data)
{
  int	i;
  int	ret;

  set_zero(data);
  if (argc == 1)
    {
      fill_with_default(data);
      return (0);
    }
  i = 1;
  while (i < argc)
    {
      if ((ret = first_part(argv, data, i)) != 0)
	return (ret);
      if (my_strcmp("-h", argv[i]) == 0)
	return (print_help(1));
      if (my_strcmp("-p", argv[i]) == 0)
	data->human = 1;
      i++;
    }
  fill_with_default(data);
  return (0);
}

int	make_plate(t_alum *data)
{
  int	i;
  int	increm;
  int	x;

  if ((data->plate = malloc(sizeof(bool*) * data->nb_lines)) == NULL)
    return (- 1);
  i = 0;
  increm = data->nb_width;
  while (i < data->nb_lines)
    {
      x = 0;
      if ((data->plate[i] = malloc(sizeof(bool) * increm)) == NULL)
	return (- 1);
      while (x < increm)
	{
	  data->plate[i][x] = true;
	  x++;
	}
      i++;
      increm += 2;
    }
  return (0);
}
