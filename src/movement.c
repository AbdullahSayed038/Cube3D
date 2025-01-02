#include "../includes/cube3d.h"

int is_valid_move(int x, int y, int map[MAP_HEIGHT][MAP_WIDTH])
{
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT)
        return (0); // Out of bounds
    return (map[y][x] == 0); // 0 means empty space
}

void handle_movement_keys(int keycode, t_player *player, int map[MAP_HEIGHT][MAP_WIDTH])
{
    if (keycode == 119) // W
    {
        int new_x = player->x + player->dir_x * player->move_speed;
        int new_y = player->y + player->dir_y * player->move_speed;
        if (is_valid_move(new_x, new_y, map))
        {
            player->x = new_x;
            player->y = new_y;
        }
    }
    else if (keycode == 97) // A
        printf("Move left\n");
    else if (keycode == 115) // S
        printf("Move backward\n");
    else if (keycode == 100) // D
        printf("Move right\n");
}

