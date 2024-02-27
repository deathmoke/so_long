NAME = so_long

SRCS_DIR = srcs/
MLX_DIR = mlx/
INCLUDE = includes/

MLX_LIB = libmlx_Linux.a

CC = gcc -Wall -Wextra -Werror
CFLAGS = -lm
MLX_FLAGS = -lX11 -lXext

SRCS = main.c gnl/get_next_line.c gnl/get_next_line_utils.c map_1.c movement.c interact.c ft_putnbr.c tester.c tester_2.c \
		map_2.c movement_utilis.c enemy_contact.c enemy_move_utilis.c move_enemies.c detect.c attack.c putcount.c \
		ft_itoa.c endscreen.c

OBJECTS = $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

BONUS_MODE = 0

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -D BONUS_MODE=$(BONUS_MODE)

all: mlx $(NAME)

mlx:
	make -sC $(MLX_DIR)

$(NAME): $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) $(MLX_DIR)$(MLX_LIB) $(MLX_FLAGS) -o $@ -I$(MLX_DIR) -I$(INCLUDE)

bonus: BONUS_MODE = 1
bonus: clean mlx $(NAME)

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)
		make clean -sC $(MLX_DIR)

re: fclean all

.PHONY: mlx