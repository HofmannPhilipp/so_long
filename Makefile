CC = cc
CFLAGS = -Wall -Werror -Wextra -I./mlx/include
NAME = so_long
SRCS = main.c map.c utils.c render.c validation.c game.c player.c

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
	cmake $(LIBMLX_DIR) -B$(LIBMLX_DIR)/build && cmake --build $(LIBMLX_DIR)/build -j4

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	rm -rf $(LIBMLX_DIR)/build

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re