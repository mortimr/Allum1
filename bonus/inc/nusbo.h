/*
** nusbo.h for bonus in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Feb 20 10:57:56 2016 Iulian Rotaru
** Last update Sun Feb 21 14:36:44 2016 Iulian Rotaru
*/

#ifndef NUSBO_H_
# define NUSBO_H_

# include <lapin.h>

typedef struct		s_text
{
  int			police_size;
  unsigned int		fg;
  t_bunny_position	pos;
  int			x;
  int			y;
}			t_text;

typedef struct	s_alum
{
  char		nb_width;
  char		nb_lines;
  char		winner;
  bool		human;
  int		**plate;
  bool		dany;
}		t_alum;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*lol;
  t_bunny_pixelarray	*allum;
  t_bunny_pixelarray	*allum_off;
  t_alum		*alum;
  t_bunny_pixelarray	*font;
}			t_data;

typedef struct		s_area_text
{
  int			x;
  int			y;
  int			i;
  int			j;
  int			ratio;
  t_bunny_position	blit;
  unsigned int		*ptrr;
  unsigned int		*ptr;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*extract;
  t_bunny_position	*area;
  t_text		*text;
}			t_area_text;

t_bunny_response	loop(void *info);
t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton button,
			      void *info);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *info);
void			bg_loop_next(int *round, unsigned int *base);
void			bg_loop(int *x, t_bunny_pixelarray *pix, int *round,
				t_color *color);
void			increm_setter(int *increm, int *round);
void			prepare_first_text(t_text *text);
int			matches_left(t_alum *data);
t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mousebutton button,
			      void *info);
void			check_click(t_bunny_position *pos, int *x,
				    t_data *data);
int			selected(t_alum *data);
int			check_argv(int argc, char **argv, t_alum *data);
int			first_part(char **argv, t_alum *data, int i);
int			is_it_num(char *str);
int			my_strcmp(char *one, char *two);
int			print_help(int ret);
int			my_strlen(const char *str);
int			my_getnbr(const char *nb);
void			set_zero(t_alum *data);
void			my_putchar(char c);
int			my_putstr(char *str);
void			my_bunny_blit(t_bunny_pixelarray *big,
				      t_bunny_pixelarray *small,
				      t_bunny_position *pos,
				      int mode);
void			set_default_pos(t_bunny_position *place,
					t_bunny_position *pos);
unsigned int		get_mix_color(t_bunny_pixelarray *pix, int idx,
			      unsigned int color);
void			main_under_boucle(t_area_text *v);
void			main_boucle(t_area_text *v);
void			copy_area(t_bunny_pixelarray *pix,
				  t_bunny_pixelarray *extract,
				  t_bunny_position *area,
				  t_text *text);
int			ps(t_bunny_position *pos, t_text *text);
void			my_blitstr(char *str,
				   t_bunny_pixelarray *pix,
				   t_bunny_pixelarray *text_pix,
				   t_text *text);
int			*get_tab(t_alum *data);
int			*more_than_two(t_alum *data, int *tab, int *out);
int			*two_only(t_alum *data, int *tab, int *out);
int			*one_only(t_alum *data, int *tab, int *out);
int			*find_best_combo(t_alum *data);
void			set_board(t_alum *data);
int			live(t_alum *data);
void			take_off(t_alum *data, int line, int matches);
int			check_if_line_empty(t_alum *data, int line);
int			make_plate(t_alum *data);
void			pair_way(t_alum *data, int *combo);
int			add_one(t_alum *data, int line);
int			how_many_remain(int *combo, t_alum *data);
int			how_many_one(t_alum *data);
int			get_nb_matches_biggest(t_alum *data);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *info);
int			update_plate(t_data *data);
void			loser_animation(t_data *data);
void			dany_part_ani(t_data *data, int i);
void			fill_text_one(t_text *text, int i);
void			fancy_background_rand(t_bunny_pixelarray *pix);
void			disp_board(t_data *data);
void			game_state(t_data *data);
void			titler(t_data *data);
t_bunny_response	loop(void *info);
int			find_bigger(int *tab, t_alum *data);
int			find_small(int *tab, t_alum *data);
int			nb_heaps(int *tab, t_alum *data);
int			count_matches(t_alum *data);
int			count_lines(t_alum *data);
unsigned int		color_mixer(unsigned int one, unsigned int add);
int			ai_turn(t_alum *data);
void			fancy_background(t_bunny_pixelarray *pix);
void			increm_setter(int *increm, int *round);
void			bg_loop(int *x, t_bunny_pixelarray *pix, int *round,
				t_color *color);
void			bg_loop_next(int *round, unsigned int *base);

#endif /* !NUSBO_H_ */
