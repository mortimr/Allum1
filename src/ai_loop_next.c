/*
** ai_loop_next.c for allum in /home/rotaru_i/Coding/CPE/CPE_2015_Allum1/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Feb 21 21:57:00 2016 Iulian Rotaru
** Last update Sun Feb 21 21:58:23 2016 Iulian Rotaru
*/

#include "allum.h"

int	ai_loop_next(t_alum *data)
{
  if (ai_human_setuper("Your turn:\n", data) == - 1)
    return (- 1);
  if (live(data) == 1)
    data->winner = - 1;
  else
    {
      if (ai_setuper("AI's turn...\n", data) == - 1)
	return (- 1);
    }
  if (live(data) == 1 && data->winner == 0)
    data->winner = 1;
  return (0);
}
