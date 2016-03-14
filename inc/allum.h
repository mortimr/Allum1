/*
** allum.h for allum in /home/rotaru_i/Coding/CPE/CPE_2015_Allum1/inc
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 18 19:02:36 2016 Iulian Rotaru
** Last update Sun Feb 21 21:59:09 2016 Iulian Rotaru
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# include <stdlib.h>
# include <stdbool.h>

typedef struct		s_alum
{
  bool			human;
  bool			lives;
  bool			lines;
  bool			width;
  char			winner;
  bool			**plate;
  unsigned char		nb_lives;
  unsigned char		nb_lines;
  unsigned char		nb_width;
}			t_alum;

char	*get_term_line();
int	live(t_alum *data);
void	my_putchar(char c);
void	my_put_nbr(int nb);
int	print_help(int ret);
int	my_putstr(char *str);
int	is_it_num(char *str);
char	*my_strdup(char *str);
void	set_zero(t_alum *data);
int	play_turn(t_alum *data);
void	put_plate(t_alum *data);
void	set_board(t_alum *data);
int	make_plate(t_alum *data);
int	ai_version(t_alum *data);
int	ai_loop_next(t_alum *data);
int	how_many_one(t_alum *data);
int	my_strlen(const char *str);
int	my_getnbr(const char *str);
int	versus_version(t_alum *data);
void	norm_pls(int *i, char *getter);
int	*find_best_combo(t_alum *data);
int	my_strcmp(char *one, char *two);
int	add_one(t_alum *data, int line);
int	nb_heaps(int *tab, t_alum *data);
int	ai_message(int matches, int line);
int	find_small(int *tab, t_alum *data);
int	find_bigger(int *tab, t_alum *data);
int	ai_setuper(char *say, t_alum *data);
int	get_nb_matches_biggest(t_alum *data);
int	ai_human_setuper(char *say, t_alum *data);
int	how_many_remain(int *combo, t_alum *data);
int	check_if_line_empty(t_alum *data, int line);
int	third_part(char **argv, t_alum *data, int i);
void	take_off(t_alum *data, int line, int matches);
int	check_argv(int argc, char **argv, t_alum *data);
int	check_line_error(char *getter, t_alum *data, int line);
int	get_written_matches(int *matches, t_alum *data, int *line);
int	check_matches_error(char *getter, t_alum *data, int line, int matches);

#endif /* !ALLUM_H_ */
