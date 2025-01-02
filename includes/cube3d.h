#ifndef CUBE3D_H
# define CUBE3D_H

# include "minilibx-mac/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600
# define FOV 30
# define PIXEL 10
# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define CELL_SIZE 20

# ifdef __APPLE__ // macOS key codes
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_ESC 53
# else // Linux key codes
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_ESC 65307
# endif

// Player structure
typedef struct s_player {
    float x;           // Player's x-coordinate
    float y;           // Player's y-coordinate
    float dir_x;       // Direction vector x
    float dir_y;       // Direction vector y
    float move_speed;  // Speed of movement
    float rot_speed;   // Speed of rotation
} t_player;

// Cube and face structures
typedef struct s_cord {
    float x;
    float y;
    float z;
} t_cord;

typedef struct s_cube {
    t_cord center;
    t_cord Fface[4];
    t_cord Bface[4];
} t_cube;

// MiniLibX structure
typedef struct s_mlx {
    void    *mlx;
    void    *win;
} t_mlx;

// Enum for cube face identification
enum FACE {
    FRONT,
    BACK,
};

// Prototypes

// Key handling
int     handle_keypress(int keycode, t_mlx *mlx, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH]);
int     close_window(t_mlx *mlx);

// Collision and movement
int     is_valid_move(int x, int y, int map[MAP_HEIGHT][MAP_WIDTH]);
void    handle_movement_keys(int keycode, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH]);

// Drawing and rendering
void    draw_grid_x(t_mlx *cub, int diff);
void    draw_grid_y(t_mlx *cub, int diff);
void    draw_map(t_mlx *mlx, int map[MAP_HEIGHT][MAP_WIDTH]);
void    draw_player(t_mlx *mlx, t_player *player);
void    render_scene(t_mlx *mlx, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH]);

// Cube drawing
int     draw_line(t_mlx *cub, t_cord cord0, t_cord cord1);
void    init_cord(t_cord *cord, float x, float y, float z);
int     draw_cube(t_mlx *cub, int size);

#endif
