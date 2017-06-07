##
## Makefile for lol in /home/tetra/rendu/psu/PSU_2016_zappy
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Wed Jun  7 15:57:14 2017 Arthur Josso
##

NAME	=	zappy_server

CC	=	gcc

INC	=	./inc/

CFLAGS	+=	-I$(INC)	\
		-Wall -Wextra

LDFLAGS	+=

DEV_FLAG	=	-g -D IN_DEV

SRC		=	./src/

SRC_PARSE	=	$(SRC)parse/

SRC_UTILS	=	$(SRC)utils/

SRC_CORE	=	$(SRC)core/

SRCS	=	$(SRC)main.c			\
		$(SRC_PARSE)run.c		\
		$(SRC_PARSE)funcs.c		\
		$(SRC_UTILS)alloc.c		\
		$(SRC_UTILS)cleaner.c		\
		$(SRC_UTILS)cleaner_utils.c	\
		$(SRC_UTILS)error.c		\
		$(SRC_UTILS)string.c		\
		$(SRC_UTILS)checker.c		\
		$(SRC_CORE)run.c		\
		$(SRC_CORE)client_init.c	\
		$(SRC_CORE)client_io.c		\
		$(SRC_CORE)client_manager.c	\
		$(SRC_CORE)fd_list.c		\
		$(SRC_CORE)init.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

%.o:		%.c
		@echo [Compiling]: $<
		@$(CC) $(DEV_FLAG) $(CFLAGS) -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
