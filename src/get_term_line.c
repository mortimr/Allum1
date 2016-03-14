/*
** get_term_line.c for allum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Fri Feb 19 19:47:14 2016 Iulian Rotaru
** Last update Fri Feb 19 20:32:29 2016 Iulian Rotaru
*/

#include <unistd.h>
#include <stdlib.h>
#include "allum.h"

char		*get_term_line()
{
  static char	s[1024];
  char		buffer;
  int		i;

  buffer = - 1;
  i = 0;
  s[i] = 0;
  while (buffer != '\n' && buffer && read(0, &buffer, 1) > 0)
    {
      if (i < 1000 && buffer != '\n' && buffer)
	s[i] = buffer;
      i++;
    }
  s[i] = 0;
  if (i == 0)
    {
      return (NULL);
    }
  return (s);
}
