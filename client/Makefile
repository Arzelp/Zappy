##
## Makefile for lol in /client/
##
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
##
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Fri Jun 16 14:28:42 2017 Frederic Oddou
##

NAME	=	zappy_ai

CC	=	gcc

INC	=	./inc/

CFLAGS	+=	-I$(INC)		\
		-Wall -Wextra

LDFLAGS	+=

SRC	=	./src/
PARSE	=	$(SRC)parse/
UTILS	=	$(SRC)utils/
CONNECT	=	$(SRC)connect/
CMD	=	$(SRC)commands/

SRCS	=	$(SRC)main.c			\
		$(UTILS)checker.c		\
		$(PARSE)parse.c			\
		$(PARSE)funcs.c			\
		$(CONNECT)open_socket.c		\
		$(CONNECT)get_player.c		\
		$(CONNECT)send_msg.c		\
		$(CONNECT)receive_msg.c		\
		$(CMD)player_forward.c		\
		$(CMD)player_broadcast.c	\
		$(CMD)player_left.c		\
		$(CMD)player_right.c

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
