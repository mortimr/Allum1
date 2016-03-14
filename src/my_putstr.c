/*
** my_putstr.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:19:20 2016 Iulian Rotaru
** Last update Thu Feb 18 20:03:34 2016 Iulian Rotaru
*/

#include "allum.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (i);
}

int	print_help(int ret)
{
  my_putstr("Help :\n");
  my_putstr("-l : sets number of lifes for each player (default is 1)\n");
  my_putstr("-L : sets number of lines (default is 4)\n");
  my_putstr("-w : sets starting number of matches on line 1 (default is 1)\n");
  my_putstr("-h : displays help menu\n");
  my_putstr("Have fun playing Alum-1 !\n");
  my_putstr("Made by rotaru_i\n");
  return (ret);
}

int	my_strcmp(char *one, char *two)
{
  int	i;

  i = 0;
  if (one == NULL || two == NULL)
    return (1);
  while (one[i] && two[i])
    {
      if (one[i] != two[i])
	return (1);
      i++;
    }
  if (one[i] != two[i])
    return (1);
  return (0);
}

int	is_it_num(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && (str[i] != '-'))
	return (1);
      i++;
    }
  return (0);
}

int	third_part(char **argv, t_alum *data, int i)
{
  if (my_strcmp("-L", argv[i]) == 0)
    {
      data->lines = 1;
      if (argv[i + 1] == NULL)
	return (print_help(- 1));
      if (is_it_num(argv[i + 1]) == 1)
	return (print_help(- 1));
      if (((data->nb_lines = my_getnbr(argv[i + 1])) <= 0) ||
	  ((data->nb_lines = my_getnbr(argv[i + 1])) > 20))
	return (print_help(- 1));
    }
  return (0);
}
