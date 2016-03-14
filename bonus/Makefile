##
## Makefile for alum1 in /home/rotaru_i
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Mon Feb  8 21:47:59 2016 Iulian Rotaru
## Last update Sat Feb 20 12:01:54 2016 Iulian Rotaru
##

CC	= gcc

CFLAGS	+= -Wall -Wextra -ansi -pedantic -Werror -Wunused\
	   -I/home/${USER}/.froot/include \
	   -L/home/${USER}/.froot/lib     \
	   -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
	   -I./inc

LIB	=  -Wall -Wextra -ansi -pedantic -Werror -Wunused\
	   -I/home/${USER}/.froot/include \
	   -L/home/${USER}/.froot/lib     \
	   -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
	   -I./inc

RM	= rm -rf

NAME	= bonus


SRCS	= main.c \
	  my_bunny_blit.c \
	  my_blitstr.c \
	  color_mixer.c \
	  my_strlen.c \
	  print_help.c \
	  make_plate.c \
	  count_lines.c \
	  make_tab.c \
	  get_biggest_matches.c \
	  ai_turn.c \
	  fancy_background_rand.c \
	  selected.c \
	  fill_text_one.c

OBJ	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo -e "\033[3;35m"
	@cat ../title.txt
	@echo -e "\033[3;34m"
	@cat lapin.txt
	@echo -e " \033[0m"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
