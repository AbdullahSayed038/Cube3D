#include "../includes/cube3d.h"

int close_window(t_mlx *mlx)
{
    mlx_destroy_window(mlx->mlx, mlx->win);
    exit(0);
    return (0);
}


// Handle arrow keys (Up, Down, Left, Right)
void handle_arrow_keys(int keycode)
{
    if (keycode == 65362) // Up arrow
        printf("Look up\n");
    else if (keycode == 65361) // Left arrow
        printf("Look left\n");
    else if (keycode == 65364) // Down arrow
        printf("Look down\n");
    else if (keycode == 65363) // Right arrow
        printf("Look right\n");
}

void render_scene(t_mlx *mlx, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH])
{
    mlx_clear_window(mlx->mlx, mlx->win); // Clear the screen
    draw_map(mlx, map);                  // Redraw the map
    draw_player(mlx, player);            // Redraw the player
}

int handle_keypress(int keycode, t_mlx *mlx, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH])
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(mlx->mlx, mlx->win);
        exit(0);
    }
    handle_movement_keys(keycode, player, map);
    render_scene(mlx, player, map); // Redraw the scene
    return (0);
}

int main(void)
{
    t_mlx mlx;
    t_player player;
    int map[MAP_HEIGHT][MAP_WIDTH] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Initialize player
    player.x = 5.0;    // Start in the center of the map
    player.y = 5.0;
    player.dir_x = 1.0;  // Facing right
    player.dir_y = 0.0;
    player.move_speed = 0.2;
    player.rot_speed = 0.1;

    // Initialize MiniLibX
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Cube3D");
}
