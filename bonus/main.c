/*
** main.c for alum1 in /home/rotaru_i/Coding/CPE/CPE_2015_Allum1/src
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Mon Feb  8 21:28:27 2016 Iulian Rotaru
** Last update Sun Feb 21 21:54:13 2016 Iulian Rotaru
*/

#include <lapin.h>
#include <stdlib.h>
#include "nusbo.h"

int		load_dany_pls(t_data *data)
{
  if (((data->allum = bunny_load_pixelarray("dany.bmp")) == NULL) ||
      ((data->allum_off = bunny_load_pixelarray("dany_off.bmp")) == NULL))
    return (- 1);
  return (0);
}

int		load_allum_pls(t_data *data)
{
  if (((data->allum = bunny_load_pixelarray("allum.bmp")) == NULL) ||
      ((data->allum_off = bunny_load_pixelarray("allum_off.bmp")) == NULL))
    return (- 1);
  return (0);
}

int		choice_loading(t_data *data)
{
  if (data->alum->dany == true)
    {
      if (load_dany_pls(data) == - 1)
	return (- 1);
    }
  else
    {
      if (load_allum_pls(data) == - 1)
	return (- 1);
    }
  return (0);
}

int		launch_bunnygame(t_data *data)
{
  if ((data->win = bunny_start(1920, 1080, 1, "Allum-1")) == NULL)
    return (- 1);
  if ((data->pix = bunny_new_pixelarray(1920, 1080)) == NULL)
    return (- 1);
  if ((data->font = bunny_load_pixelarray("font.png")) == NULL)
    return (- 1);
  if ((data->lol = bunny_load_pixelarray("lol.png")) == NULL)
    return (- 1);
  if (choice_loading(data) == - 1)
    return (- 1);
  bunny_set_loop_main_function((t_bunny_loop)loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_set_click_response((t_bunny_click)click);
  bunny_loop(data->win, 60, data);
  return (EXIT_ON_SUCCESS);
}

int		main(int argc, char **argv)
{
  t_alum	data;
  int		check_ret;
  t_data	info;

  if ((check_ret = check_argv(argc, argv, &data)) == - 1)
    return (- 1);
  if (check_ret == 1)
    return (0);
  if (make_plate(&data) == - 1)
    return (- 1);
  info.alum = &data;
  return (launch_bunnygame(&info));
}
