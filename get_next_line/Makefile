CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = get_next_line_utils.c get_next_line.c
OBJ = $(SRC:.c=.o)

NAME = get_next_line.a



all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o : %.c get_next_line.h
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@${RM} $(OBJ)

fclean:
	@${RM} $(NAME) $(OBJ)

re : fclean all