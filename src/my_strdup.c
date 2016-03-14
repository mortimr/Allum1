/*
** my_strdup.c for line_sender in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed Jan 27 23:24:09 2016 Iulian Rotaru
** Last update Fri Feb 19 20:25:12 2016 Iulian Rotaru
*/

#include "allum.h"

char	*my_strdup(char *targ)
{
  char	*dest;
  int	i;

  if ((dest = malloc(sizeof(char) * (my_strlen(targ) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (targ[i])
    {
      dest[i] = targ[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
