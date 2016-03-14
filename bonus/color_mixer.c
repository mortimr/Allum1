/*
** color_mixer.c for alum in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 18:59:49 2016 Iulian Rotaru
** Last update Sat Feb 20 11:29:27 2016 Iulian Rotaru
*/

#include <lapin.h>

unsigned int	color_mixer(unsigned int one, unsigned int add)
{
  t_color	first;
  t_color	adder;
  t_color	out;
  double	coeff;

  first.full = one;
  adder.full = add;
  coeff = adder.argb[3] / 256.0;
  out.argb[0] = adder.argb[0] * coeff + first.argb[0] * (1.0 - coeff);
  out.argb[1] = adder.argb[1] * coeff + first.argb[1] * (1.0 - coeff);
  out.argb[2] = adder.argb[2] * coeff + first.argb[2] * (1.0 - coeff);
  out.argb[3] = adder.argb[3] * coeff + first.argb[3] * (1.0 - coeff);
  return (out.full);
}
