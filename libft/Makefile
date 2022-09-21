NAME = libft.a

PATH_INC = ./includes/
PATH_OBJ = ./objects/
PATH_SRC = ./sources/

SRCS = $(addprefix $(PATH_SRC),\
	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_get_next_line.c\
	ft_htoi.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c\
	ft_matrixfree.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_pointerfree.c\
	ft_printf_arg_c.c\
	ft_printf_arg_p.c\
	ft_printf_arg_sdi.c\
	ft_printf_arg_ux.c\
	ft_printf_countdigits.c\
	ft_printf_validation.c\
	ft_printf.c\
	ft_putbase.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_splitlen.c\
	ft_striteri.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_strjoin.c\
	ft_strmapi.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c)

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@cc $(CFLAGS) -I $(PATH_INC) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: re fclean clean all
