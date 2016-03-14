/*
** print_help.c for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 11:03:29 2016 Iulian Rotaru
** Last update Sat Feb 20 11:21:03 2016 Iulian Rotaru
*/

#include "nusbo.h"

int	print_help(int ret)
{
  my_putstr("Help :\n");
  my_putstr("-d : dany mode /!\\ graphical version only /!\\\n");
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
      if ((str[i] < '0' || str[i] > '9') && (str[i != '-']))
	return (1);
      i++;
    }
  return (0);
}

int	first_part(char **argv, t_alum *data, int i)
{
  if (my_strcmp("-d", argv[i]) == 0)
    data->dany = 1;
  return (0);
}

int	check_argv(int argc, char **argv, t_alum *data)
{
  int	i;
  int	ret;

  set_zero(data);
  data->dany = 0;
  data->human = 0;
  data->nb_lines = 4;
  data->nb_width = 1;
  if (argc == 1)
    {
      return (0);
    }
  i = 1;
  while (i < argc)
    {
      if ((ret = first_part(argv, data, i)) != 0)
	return (ret);
      if (my_strcmp("-h", argv[i]) == 0)
	return (print_help(1));
      i++;
    }
  return (0);
}
