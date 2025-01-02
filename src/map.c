#include "../includes/cube3d.h"

void draw_map(t_mlx *mlx, int map[MAP_HEIGHT][MAP_WIDTH])
{
    int x, y;

    for (y = 0; y < MAP_HEIGHT; y++)
    {
        for (x = 0; x < MAP_WIDTH; x++)
        {
            if (map[y][x] == 1) // Wall
            {
                int screen_x = x * CELL_SIZE;
                int screen_y = y * CELL_SIZE;
                mlx_pixel_put(mlx->mlx, mlx->win, screen_x, screen_y, 0xFFFFFF);
            }
        }
    }
}

void draw_player(t_mlx *mlx, t_player *player)
{
    int screen_x = player->x * CELL_SIZE;
    int screen_y = player->y * CELL_SIZE;
    mlx_pixel_put(mlx->mlx, mlx->win, screen_x, screen_y, 0xFF0000); // Red dot for player
}

