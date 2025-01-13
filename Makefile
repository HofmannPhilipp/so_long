CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
SRCS = main.c map.c utils.c render.c validation.c game.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
MINILIBX_DIR = ./minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.dylib
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit -lz
GREEN = \033[32m
YELLOW = \033[33m
NC = \033[0m

all: $(NAME)


$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MINILIBX_FLAGS) -o $(NAME)
	@install_name_tool -change libmlx.dylib $(MINILIBX_DIR)/libmlx.dylib $(NAME)
	@echo "$(GREEN)Compiled Successfully 😎$(NC)"

$(MINILIBX):
	@echo "$(YELLOW)🚧Compiling MINILIBX🚧$(NC)"
	@make -C $(MINILIBX_DIR)

$(LIBFT):
	@echo "$(YELLOW)🚧Compiling LIBFT🚧$(NC)"
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re