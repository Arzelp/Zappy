##
## Makefile for makefile in /home/paskal/rendu/System_Unix/PSU_2016_zappy/graphic/
##
## Made by Paskal Arzel
## Login   <paskal.arzel@epitech.eu>
##
## Started on  Thu Jun 15 17:36:53 2017 Paskal Arzel
## Last update Thu Jun 15 17:37:02 2017 Paskal Arzel
##

NAME	=	zappy_graphic

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
