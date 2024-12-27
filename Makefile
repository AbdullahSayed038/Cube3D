NAME        = cube3d
SRCS        = src/main.c src/draw.c src/grid.c src/cube.c
OBJS        = $(SRCS:.c=.o)
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g

# Paths
LIBFT_PATH  = includes/libft
LIBFT       = $(LIBFT_PATH)/libft.a
MLX_PATH    = includes/minilibx-linux
MLX_LIB     = $(MLX_PATH)/libmlx.a

# Determine operating system
OS := $(shell uname)

ifeq ($(OS), Darwin) # macOS
LIBS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
else # Linux
LIBS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
endif

LIBS += -L$(LIBFT_PATH) -lft

# Rules
all: $(MLX_LIB) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
