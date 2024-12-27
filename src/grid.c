#include "../includes/cube3d.h"

void	draw_grid_x(t_mlx *cub, int diff)
{
	t_cord	cord0;
	t_cord	cord1;

	cord0.x = 0;
	cord0.y = 0;
	cord1.x = 0;
	cord1.y = HEIGHT;
	while (cord0.x < WIDTH)
	{
		draw_line(cub, cord0, cord1);
		cord0.x += diff;
		cord1.x += diff;
	}
}

void	draw_grid_y(t_mlx *cub, int diff)
{
	t_cord	cord0;
	t_cord	cord1;

	cord0.x = 0;
	cord0.y = 0;
	cord1.x = WIDTH;
	cord1.y = 0;
	while (cord0.y < HEIGHT)
	{
		draw_line(cub, cord0, cord1);
		cord0.y += diff;
		cord1.y += diff;
	}
}
