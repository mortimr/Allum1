/*
** main.c for alum1 in /home/rotaru_i/Coding/CPE/CPE_2015_Allum1/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Mon Feb  8 21:28:27 2016 Iulian Rotaru
** Last update Thu Feb 18 20:19:17 2016 Iulian Rotaru
*/

#include "allum.h"

int		launch_game(t_alum *data)
{
  if (data->human == 1)
    return (versus_version(data));
  else
    return (ai_version(data));
  return (0);
}

int		main(int argc, char **argv)
{
  t_alum	data;
  int		check_ret;

  if ((check_ret = check_argv(argc, argv, &data)) == - 1)
    return (- 1);
  if (check_ret == 1)
    return (0);
  if (make_plate(&data) == - 1)
    return (- 1);
  return (launch_game(&data));
}
