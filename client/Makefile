##
## Makefile for lol in /client/
##
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
##
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Sat Jul  1 01:11:12 2017 Paskal Arzel
##

NAME	=	zappy_ai

CC	=	gcc -g

INC	=	./inc/

CFLAGS	+=	-I$(INC)		\
		-Wall -Wextra -g

LDFLAGS	+= -lm

SRC	=	./src/
PARSE	=	$(SRC)parse/
UTILS	=	$(SRC)utils/
QUEUE	=	$(UTILS)queue/
CONNECT	=	$(SRC)connect/
CMD	=	$(SRC)commands/
GAME	=	$(SRC)game/
IA	= 	$(SRC)ia/
IATP	=	$(IA)teamplay/

SRCS	=	$(SRC)main.c			\
		$(SRC)core.c			\
		$(UTILS)checker.c		\
		$(UTILS)trim.c			\
		$(UTILS)strtok_single.c		\
		$(UTILS)replace_letter.c	\
		$(UTILS)get_objects_type.c	\
		$(UTILS)is_object.c		\
		$(UTILS)debug.c			\
		$(QUEUE)queue_class.c		\
		$(QUEUE)queue_get.c		\
		$(QUEUE)queue_insert.c		\
		$(PARSE)parse.c			\
		$(PARSE)funcs.c			\
		$(CONNECT)open_socket.c		\
		$(CONNECT)close_socket.c	\
		$(CONNECT)get_player.c		\
		$(CONNECT)send_msg.c		\
		$(CONNECT)receive_msg.c		\
		$(CMD)cmd_checker.c		\
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
		$(IA)ia_main.c			\
		$(IA)check_mom.c		\
		$(IA)look.c		\
		$(IA)set_rush.c \
		$(IA)set_minimap.c \
		$(IA)select_elem.c \
		$(IA)case_analysis.c \
		$(IA)loot_case.c \
		$(IA)move.c \
		$(IA)elevate.c \
		$(IA)find_direction.c \
		$(IATP)teamplay.c \
		$(IATP)read_message.c \
		$(IATP)send_message.c \
		$(IATP)calc_pos.c \
		$(IATP)get_message.c \
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
