
NAME = so_long

CC = cc

CFLAGS = -Werror -Wextra -Wall

MLX_PATH = minilibx-linux/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

FT_PRINTF_PATH = ft_printf/

FT_PRINTF_LIB = $(FT_PRINTF_PATH)libftprintf.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = \
				background.c\
				initializer.c\
				create_map.c\
				check_path.c\
				main.c\
				map.c\
				validate_input.c

OBJECTS = $(CFILES:.c=.o)

all: compile $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -I$(MLX_PATH) -c -o $@ $<

compile:
		@make -C $(MLX_PATH) all
		@make -C $(FT_PRINTF_PATH) all

$(NAME): $(OBJECTS)
		$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
		make -C $(MLX_PATH) clean
		make -C $(FT_PRINTF_PATH) clean
		rm -f $(OBJECTS)

fclean: clean
		make -C $(FT_PRINTF_PATH) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re compile