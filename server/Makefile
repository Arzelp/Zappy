##
## Makefile for lol in /home/tetra/rendu/psu/PSU_2016_zappy
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Fri Jun 16 20:50:21 2017 Arthur Josso
##

NAME	=	zappy_server

CC	=	gcc

INC	=	./inc/

CFLAGS	+=	-I$(INC)	\
		-Wall -Wextra

LDFLAGS	+=

DEV_FLAG	=	-g

SRC		=	./src/

SRC_PARSE	=	$(SRC)parse/

SRC_UTILS	=	$(SRC)utils/

SRC_CORE	=	$(SRC)core/

SRC_CLIENT	=	$(SRC)client/

SRC_PLAYER	=	$(SRC)player/

SRC_GRAPHIC	=	$(SRC)graphic/

SRC_TASK	=	$(SRC_PLAYER)task/

SRC_G_CMD	=	$(SRC_GRAPHIC)cmd/

SRC_C_CMD	=	$(SRC_PLAYER)cmd/

SRC_T_CMD	=	$(SRC_TASK)cmd/

SRCS	=	$(SRC)main.c			\
		$(SRC_PARSE)run.c		\
		$(SRC_PARSE)funcs.c		\
		$(SRC_PARSE)team.c		\
		$(SRC_UTILS)alloc.c		\
		$(SRC_UTILS)cleaner.c		\
		$(SRC_UTILS)cleaner_utils.c	\
		$(SRC_UTILS)error.c		\
		$(SRC_UTILS)string.c		\
		$(SRC_UTILS)checker.c		\
		$(SRC_CORE)run.c		\
		$(SRC_CORE)fd_list.c		\
		$(SRC_CORE)init.c		\
		$(SRC_CORE)map.c		\
		$(SRC_CLIENT)init.c		\
		$(SRC_CLIENT)io.c		\
		$(SRC_CLIENT)manager.c		\
		$(SRC_CLIENT)cmd_io.c		\
		$(SRC_CLIENT)entity_callback.c	\
		$(SRC_CLIENT)entity_tool.c	\
		$(SRC_PLAYER)run.c		\
		$(SRC_PLAYER)init.c		\
		$(SRC_GRAPHIC)run.c		\
		$(SRC_GRAPHIC)init.c		\
		$(SRC_G_CMD)get_arg.c		\
		$(SRC_G_CMD)msz.c		\
		$(SRC_G_CMD)bct.c		\
		$(SRC_G_CMD)mct.c		\
		$(SRC_G_CMD)tna.c		\
		$(SRC_G_CMD)ppo.c		\
		$(SRC_G_CMD)plv.c		\
		$(SRC_G_CMD)pin.c		\
		$(SRC_G_CMD)sgt.c		\
		$(SRC_G_CMD)sst.c		\
		$(SRC_C_CMD)nbr_slot.c		\
		$(SRC_C_CMD)move.c		\
		$(SRC_TASK)init.c		\
		$(SRC_TASK)list.c		\
		$(SRC_TASK)time.c		\
		$(SRC_TASK)run.c		\
		$(SRC_T_CMD)move.c

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
