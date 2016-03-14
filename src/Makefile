##
## Makefile for alum1 in /home/rotaru_i
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Mon Feb  8 21:47:59 2016 Iulian Rotaru
## Last update Sun Feb 21 21:57:57 2016 Iulian Rotaru
##

CC	= gcc

RM	= rm -rf

NAME	= allum1

CFLAGS	+= -Wall			\
	   -ansi			\
	   -Wextra			\
	   -Werror			\
	   -Wunused			\
	   -I../inc			\
	   -pedantic

SRCS	= get_nb_matches_biggest.c 	\
	  check_line_error_next.c  	\
	  get_written_line.c       	\
	  get_term_line.c	   	\
	  ai_loop_next.c		\
	  second_part.c            	\
	  line_putter.c            	\
	  get_biggest.c            	\
	  my_put_nbr.c             	\
	  my_putstr.c              	\
	  tab_maker.c              	\
	  my_strdup.c			\
	  norm_pls.c		   	\
	  setuper.c                	\
	  ai_turn.c                	\
	  main.c                   

OBJ	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	cp $(NAME) ..
	@echo -e "\033[3;34m"
	@cat ../title.txt
	@echo -e " \033[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
