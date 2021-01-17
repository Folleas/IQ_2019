##
## EPITECH PROJECT, 2018
## My_runner
## File description:
## My_runner's makefile
##

SRCDIR		=		src

INCDIR		=		include

SRC     	=		$(SRCDIR)/Iq.cpp \
					$(SRCDIR)/main.cpp \

OBJ			=		$(SRC:.cpp=.o)

CC			=		g++

NAME		=		205IQ

CPPFLAGS	+=    	-I include/ -g3

all:				$(NAME)

$(NAME):			$(OBJ)
					$(CC) $(OBJ) -o $(NAME)

clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re

