##
## Makefile for lol in /home/tetra/rendu/psu/PSU_2016_zappy
##
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
##
## Started on  Tue Jun  6 13:55:56 2017 Arthur Josso
## Last update Tue Jun 20 13:25:14 2017 Frederic Oddou
##

NAME_SERVER	=	zappy_server

NAME_CLIENT	=	zappy_ai

NAME_GRAPHIC	= zappy_graphic

DIR_SERVER	=	./server/

DIR_CLIENT	=	./client/

DIR_GRAPHIC	= ./graphic/

MAKE_SILENT	=	$(MAKE) --no-print-directory -C

RM		=	rm -f

CP		=	cp

all:		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):
		@echo "---Compiling Zappy Server---"
		@$(MAKE_SILENT) $(DIR_SERVER)
		@$(CP) $(DIR_SERVER)$(NAME_SERVER) .

$(NAME_CLIENT):
		@echo "---Compiling Zappy Client---"
		@$(MAKE_SILENT) $(DIR_CLIENT)
		@$(CP) $(DIR_CLIENT)$(NAME_CLIENT) .

$(NAME_GRAPHIC):
		@echo "---Compiling Zappy Graphic---"
		@$(MAKE_SILENT) $(DIR_GRAPHIC)
		@$(CP) $(DIR_GRAPHIC)$(NAME_GRAPHIC) .

clean:
		@$(MAKE_SILENT) $(DIR_SERVER) clean
		@$(MAKE_SILENT) $(DIR_CLIENT) clean
		@$(MAKE_SILENT) $(DIR_GRAPHIC) clean

fclean:		clean
		@$(MAKE_SILENT) $(DIR_SERVER) fclean
		@$(MAKE_SILENT) $(DIR_CLIENT) fclean
		@$(MAKE_SILENT) $(DIR_GRAPHIC) clean
		@$(RM) $(NAME_GRAPHIC)
		@$(RM) $(NAME_SERVER)
		@$(RM) $(NAME_CLIENT)

re:		fclean all

.PHONY:		all clean fclean re
