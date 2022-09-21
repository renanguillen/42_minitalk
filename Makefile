NAME = minitalk

SV = server
CL = client

PATH_LIB = ./libft/
PATH_OBJ = ./objects/
PATH_SRC = ./sources/
PATH_INC = ./includes/

git:
	@git status
	@sleep 1 && echo 5 && sleep 1 && echo 4 && sleep 1 && echo 3 && sleep 1 && echo 2 && sleep 1 && echo 1 && sleep 2
	@git add .
	@git commit -m 'Automatic commit via Makefile'
	@git push