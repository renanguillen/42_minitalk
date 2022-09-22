NAME = minitalk

CL = client
SV = server

PATH_INCS = ./includes/
PATH_LIBS = ./libft/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/

SRCS_CL = $(PATH_SRCS)client.c
SRCS_SV = $(PATH_SRCS)server.c

OBJS_CL = $(PATH_OBJS)client.o
OBJS_SV = $(PATH_OBJS)server.o

CC = cc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(PATH_INCS)
LIBRARY = $(PATH_LIBS)libft.a

all: $(NAME)

$(NAME): $(SV) $(CL)

$(SV): $(OBJS_SV) $(LIBRARY)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(SV) $(OBJS_SV) $(LIBRARY)

$(OBJS_SV): $(SRCS_SV)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(CL): $(OBJS_CL) $(LIBRARY)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(CL) $(OBJS_CL) $(LIBRARY)

$(OBJS_CL): $(SRCS_CL)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBRARY):
	make -C $(PATH_LIBS)

clean:
	@make clean -C $(PATH_LIBS)
	rm -rf $(PATH_OBJS)

fclean: clean
	@make fclean -C $(PATH_LIBS)
	rm $(SV) $(CL)

re: fclean all

git:
	@git status
	@sleep 1 && echo 5 && sleep 1 && echo 4 && sleep 1 && echo 3 && sleep 1 && echo 2 && sleep 1 && echo 1 && sleep 2
	@git add .
	@git commit -m 'Automatic commit via Makefile'
	@git push
	@clear
	@git status