CC = cc
CFLAGS = -Wall -Werror -Wextra -I./mlx/include/MLX42 -I./libft
NAME = so_long
SRCS = main.c map.c utils.c render.c validation.c game.c player.c app.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
LIBMLX_DIR = ./mlx
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a
LIBMLX_FLAGS = -L$(LIBMLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -o $(NAME)

$(LIBMLX):
	git clone https://github.com/codam-coding-college/MLX42.git mlx
	cmake $(LIBMLX_DIR) -B$(LIBMLX_DIR)/build && cmake --build $(LIBMLX_DIR)/build

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	rm -rf mlx

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re