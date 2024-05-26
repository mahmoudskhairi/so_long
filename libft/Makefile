CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
ft_strcmp.c  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_print_error.c\
ft_lstfree_bonus.c ft_free.c ft_free_array.c ft_free_tab.c ft_sort_tab.c ft_lstprev.c  ft_is_sorted.c ft_init_stack.c\
swap.c rotate.c reverse_rotate.c push.c ft_indexing.c ft_sort_stack.c ft_print_stack.c ft_sort_functions.c\



OBJ = ${SRC:.c=.o}
NAME = libft.a

all: ${NAME}

${NAME}: ${OBJ} ${OBONUS}
	@ar rcs ${NAME} ${OBJ}

%.o:%.c libft.h
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm ${OBJ}

fclean:
	@rm ${NAME} ${OBJ}

re: fclean all

.PHONY : all bonus clean fclean re
