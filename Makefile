##
## Makefile for lol in /home/tetra/rendu/psu/PSU_2016_zappy
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Tue Jun  6 13:55:56 2017 Arthur Josso
## Last update Tue Jun  6 14:22:08 2017 Arthur Josso
##

NAME_SERVER	=	zappy_server

NAME_CLIENT	=	zappy_ai

DIR_SERVER	=	./server/

DIR_CLIENT	=	./client/

MAKE_SILENT	=	$(MAKE) --no-print-directory -C

RM		=	rm -f

CP		=	cp

all:		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):
		@$(MAKE_SILENT) $(DIR_SERVER)
		@$(CP) $(DIR_SERVER)$(NAME_SERVER) .

$(NAME_CLIENT):
		@$(MAKE_SILENT) $(DIR_CLIENT)
		@$(CP) $(DIR_CLIENT)$(NAME_CLIENT) .

clean:
		@$(MAKE_SILENT) $(DIR_SERVER) clean
		@$(MAKE_SILENT) $(DIR_CLIENT) clean

fclean:		clean
		@$(MAKE_SILENT) $(DIR_SERVER) fclean
		@$(MAKE_SILENT) $(DIR_CLIENT) fclean
		@$(RM) $(NAME_SERVER)
		@$(RM) $(NAME_CLIENT)

re:		fclean all

.PHONY:		all clean fclean re
