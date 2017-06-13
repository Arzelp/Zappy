##
## Makefile for lol in /home/tetra/rendu/psu/PSU_2016_zappy
##
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
##
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Tue Jun 13 17:16:02 2017 Paskal Arzel
##

NAME	=	zappy_ai

CC	=	gcc

INC	=	./inc/

CFLAGS	+=	-I$(INC)		\
		-Wall -Wextra

LDFLAGS	+=

SRC	=	./src/

SRCS	=	$(SRC)main.c \
			$(SRC)help.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

%.o:		%.c
		@echo [Compiling]: $<
		@$(CC) $(CFLAGS) -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
