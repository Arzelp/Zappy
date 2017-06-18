##
## Makefile for lol in /client/
##
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
##
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Sun Jun 18 18:54:21 2017 Frederic Oddou
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
GAME	=	$(SRC)game/

SRCS	=	$(SRC)main.c			\
		$(UTILS)checker.c		\
		$(UTILS)trim.c			\
		$(UTILS)strtok_single.c		\
		$(UTILS)replace_letter.c	\
		$(UTILS)get_objects_type.c	\
		$(UTILS)debug.c			\
		$(PARSE)parse.c			\
		$(PARSE)funcs.c			\
		$(CONNECT)open_socket.c		\
		$(CONNECT)close_socket.c	\
		$(CONNECT)get_player.c		\
		$(CONNECT)send_msg.c		\
		$(CONNECT)receive_msg.c		\
		$(CMD)player_forward.c		\
		$(CMD)player_broadcast.c	\
		$(CMD)player_inventory.c	\
		$(CMD)player_incantation.c	\
		$(CMD)player_left.c		\
		$(CMD)player_right.c		\
		$(CMD)player_eject.c		\
		$(CMD)player_fork.c		\
		$(CMD)player_connect_nbr.c	\
		$(CMD)player_take.c		\
		$(CMD)player_set.c		\
		$(CMD)player_look.c		\
		$(GAME)elevation.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

%.o:		%.c
		@echo [Compiling]: $<
		@$(CC) $(CFLAGS) -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

debug:
		@make re CC="gcc -D DEBUG_MODE" -C ./ -f Makefile -s

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re debug $(NAME)
