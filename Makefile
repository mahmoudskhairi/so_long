CC= cc
CFLAGS= -Wall -Wextra -Werror
RM = rm -rf
MLX_FLAGS = ../MLX42/build/libmlx42.a ../MLX42/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit
libft = ./libft/libft.a
get_next_line = ./get_next_line/get_next_line.a
ft_printf = ./ft_printf/libftprintf.a
NAME1 = so_long
NAME2 = so_long_bonus
SO_LONG = ./mandatory/src/so_long.c ./mandatory/src/utils1.c  ./mandatory/src/check_map.c ./mandatory/src/path_comp.c ./mandatory/src/hook_moves.c
SO_LONG_BONUS = ./bonus/src/so_long_bonus.c ./bonus/src/utils1_bonus.c  ./bonus/src/check_map_bonus.c ./bonus/src/path_comp_bonus.c ./bonus/src/hook_moves_bonus.c
SO_LONGO = $(SO_LONG:.c=.o)
SO_LONGO_BONUS = $(SO_LONG_BONUS:.c=.o)

all : $(NAME1)

$(NAME1) : $(libft) $(ft_printf) $(get_next_line) $(SO_LONGO) mandatory/includes/so_long.h
	@echo "                    _     _           _       _  "
	@echo "                   | |   | |         (_)     (_)"  
	@echo " ____           ___| |  _| | _   ____ _  ____ _ "  
	@echo "|    \         /___) | / ) || \ / _  | |/ ___) |" 
	@echo "| | | |_______|___ | |< (| | | ( ( | | | |   | |"  
	@echo "|_|_|_(_______|___/|_| \_)_| |_|\_||_|_|_|   |_|"  
	@echo "                                                "
	@echo "                   _                            "  
	@echo "                  | |                           " 
	@echo "  ___  ___        | | ___  ____   ____        "
	@echo " /___)/ _ \       | |/ _ \|  _ \ / _  |       "
	@echo "|___ | |_| |______| | |_| | | | ( ( | |_ _ _  "
	@echo "(___/ \___(_______)_|\___/|_| |_|\_|| (_|_|_) "
	@echo "                                (_____|        "
	@echo "									                        "
	@echo "									                        "
	@echo "make..."
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SO_LONGO) $(libft) $(ft_printf) $(get_next_line) -o $(NAME1)

$(libft):
	$(MAKE) -C ./libft

$(ft_printf):
	$(MAKE) -C ./ft_printf

$(get_next_line):
	$(MAKE) -C ./get_next_line
	
%.o:%c ./bonus/includes/so_long_bonus.h
	$(CC) -c $(CFLAGS) -Imlx $< -o $@


bonus:$(NAME2)

$(NAME2): $(libft) $(ft_printf) $(get_next_line) $(SO_LONGO_BONUS) $(UTILSO_BONUS) ./bonus/includes/so_long_bonus.h
	@echo "                    _     _           _       _  "
	@echo "                   | |   | |         (_)     (_)"  
	@echo " ____           ___| |  _| | _   ____ _  ____ _ "  
	@echo "|    \         /___) | / ) || \ / _  | |/ ___) |" 
	@echo "| | | |_______|___ | |< (| | | ( ( | | | |   | |"  
	@echo "|_|_|_(_______|___/|_| \_)_| |_|\_||_|_|_|   |_|"  
	@echo "                                                "
	@echo "                   _                            "  
	@echo "                  | |                           " 
	@echo "  ___  ___        | | ___  ____   ____        "
	@echo " /___)/ _ \       | |/ _ \|  _ \ / _  |       "
	@echo "|___ | |_| |______| | |_| | | | ( ( | |_ _ _  "
	@echo "(___/ \___(_______)_|\___/|_| |_|\_|| (_|_|_) "
	@echo "                                (_____|        "
	@echo "									                        "
	@echo "									                        "
	@echo "make..."
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(SO_LONGO_BONUS) $(libft) $(ft_printf) $(get_next_line) -o $(NAME2)

clean:
	@echo "make clean..."
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./ft_printf
	@$(MAKE) clean -C ./get_next_line

fclean:
	@echo "make fclean..."
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./ft_printf
	@$(MAKE) fclean -C ./get_next_line
	@${RM} $(NAME1) $(SO_LONGO) $(UTILSO)
	@${RM} $(NAME2) $(SO_LONGO_BONUS) $(UTILSO_BONUS)
re: fclean all
