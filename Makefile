NAME = minitalk

CL = client
SV = server

PATH_INC = ./includes/
PATH_LIB = ./libft/
PATH_OBJ = ./objects/
PATH_SRC = ./sources/

fclean:
	@make fclean -C $(PATH_LIB)

git:
	@git status
	@sleep 1 && echo 5 && sleep 1 && echo 4 && sleep 1 && echo 3 && sleep 1 && echo 2 && sleep 1 && echo 1 && sleep 2
	@git add .
	@git commit -m 'Automatic commit via Makefile'
	@git push