##
## Makefile<CPE_2015_Allum1> for allum1 in /home/rotaru_i
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Mon Feb  8 21:51:53 2016 Iulian Rotaru
## Last update Fri Feb 19 19:56:42 2016 Iulian Rotaru
##

all:
	make -C ./src

clean:
	make -C ./src clean

fclean:
	make -C ./src fclean

re:
	make -C ./src re

.PHONY: all clean fclean re
