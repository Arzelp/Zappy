##
## Makefile for lol in /home/tetra/rendu/psu/PSU_2016_zappy
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Tue Jun  6 13:53:16 2017 Arthur Josso
## Last update Wed Jun 28 17:47:03 2017 Arthur Josso
##

NAME	=	zappy_server

CC	=	gcc

INC	=	./inc/

CFLAGS	+=	-I$(INC)	\
		-Wall -Wextra

LDFLAGS	+=	-lm

DEV_FLAG	=

SRC		=	./src/

SRC_PARSE	=	$(SRC)parse/

SRC_UTILS	=	$(SRC)utils/

SRC_CORE	=	$(SRC)core/

SRC_CLIENT	=	$(SRC)client/

SRC_PLAYER	=	$(SRC)player/

SRC_GRAPHIC	=	$(SRC)graphic/

SRC_ADMIN	=	$(SRC)admin/

SRC_TASK	=	$(SRC_PLAYER)task/

SRC_EGG		=	$(SRC)egg/

SRC_G_CMD	=	$(SRC_GRAPHIC)cmd/

SRC_C_CMD	=	$(SRC_PLAYER)cmd/

SRC_T_CMD	=	$(SRC_TASK)cmd/

SRC_A_CMD	=	$(SRC_ADMIN)cmd/

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
		$(SRC_UTILS)math.c		\
		$(SRC_UTILS)time.c		\
		$(SRC_UTILS)hash.c		\
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
		$(SRC_CLIENT)tool.c		\
		$(SRC_PLAYER)run.c		\
		$(SRC_PLAYER)init.c		\
		$(SRC_PLAYER)death.c		\
		$(SRC_PLAYER)win.c		\
		$(SRC_GRAPHIC)run.c		\
		$(SRC_GRAPHIC)init.c		\
		$(SRC_GRAPHIC)for_each.c	\
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
		$(SRC_C_CMD)task_adder_1.c	\
		$(SRC_C_CMD)task_adder_2.c	\
		$(SRC_TASK)init.c		\
		$(SRC_TASK)list.c		\
		$(SRC_TASK)run.c		\
		$(SRC_T_CMD)move.c		\
		$(SRC_T_CMD)look.c		\
		$(SRC_T_CMD)inventory.c		\
		$(SRC_T_CMD)eject.c		\
		$(SRC_T_CMD)object.c		\
		$(SRC_T_CMD)incantation.c	\
		$(SRC_T_CMD)broadcast.c		\
		$(SRC_T_CMD)fork.c		\
		$(SRC_EGG)init.c		\
		$(SRC_EGG)run.c			\
		$(SRC_ADMIN)init.c		\
		$(SRC_ADMIN)run.c		\
		$(SRC_A_CMD)test.c

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
