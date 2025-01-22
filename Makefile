LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = ./lib/mlx
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBMLX_DIR)/include/MLX42 -I$(LIBFT_DIR) -I./include
NAME = so_long
SRCS =	main.c ./src/app.c ./src/events.c ./src/game.c ./src/map.c \
		./src/player.c ./src/render.c ./src/utils.c \
		./src/validation/validation.c ./src/validation/flood_fill.c ./src/validation/file_validation.c \
		./src/validation/map_validation.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR)/build -lmlx42 -lglfw -lm -pthread

$(LIBMLX):
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX_DIR)
	cmake $(LIBMLX_DIR) -B$(LIBMLX_DIR)/build && cmake --build $(LIBMLX_DIR)/build 

$(LIBFT):
	make -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	rm -rf $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
