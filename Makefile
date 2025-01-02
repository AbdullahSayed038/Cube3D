NAME        = cube3d
SRCS        = src/main.c src/draw.c src/grid.c src/cube.c src/map.c src/movement.c
OBJS        = $(SRCS:.c=.o)
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g

# Paths
LIBFT_PATH  = includes/libft
LIBFT       = $(LIBFT_PATH)/libft.a
LINUX_MLX_PATH = includes/minilibx-linux
MAC_MLX_PATH = includes/minilibx-mac

# Determine operating system
OS := $(shell uname)

ifeq ($(OS), Darwin) # macOS
MLX_PATH = $(MAC_MLX_PATH)
LIBS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
else # Linux
MLX_PATH = $(LINUX_MLX_PATH)
LIBS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
endif

MLX_LIB = $(MLX_PATH)/libmlx.a
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
	@if [ -f $(MLX_LIB) ]; then \
		echo "libmlx.a already built"; \
	else \
		$(MAKE) -C $(MLX_PATH); \
	fi

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	@if [ -d $(LINUX_MLX_PATH) ]; then \
		$(MAKE) -C $(LINUX_MLX_PATH) clean; \
	fi
	@if [ -d $(MAC_MLX_PATH) ]; then \
		$(MAKE) -C $(MAC_MLX_PATH) clean; \
	fi

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	@if [ -d $(LINUX_MLX_PATH) ]; then \
		$(MAKE) -C $(LINUX_MLX_PATH) clean; \
	fi
	@if [ -d $(MAC_MLX_PATH) ]; then \
		$(MAKE) -C $(MAC_MLX_PATH) clean; \
	fi

re: fclean all

.PHONY: all clean fclean re
