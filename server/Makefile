##
## Makefile for lol in /home/tetra/rendu/psu/PSU_2016_zappy
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Tue Jun  6 15:43:43 2017 Arthur Josso
##

NAME	=	zappy_server

CC	=	gcc -g

INC	=	./inc/

CFLAGS	+=	-I$(INC)		\
		-Wall -Wextra

LDFLAGS	+=

SRC		=	./src/

SRC_UTILS	=	$(SRC)utils/

SRCS	=	$(SRC)main.c			\
		$(SRC)parse_arg.c		\
		$(SRC)run.c			\
		$(SRC_UTILS)alloc.c		\
		$(SRC_UTILS)cleaner.c		\
		$(SRC_UTILS)cleaner_utils.c	\
		$(SRC_UTILS)error.c		\
		$(SRC_UTILS)string.c

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
