#include "../includes/cube3d.h"

void	init_cord(t_cord *cord, float x, float y, float z)
{
	cord->x = x;
	cord->y = y;
	cord->z = z;
}

float	direction(float d1, float d2)
{
	if (d1 < d2)
		return (1);
	return (-1);
}

void	calculate_slope(float *xi, float *yi, int *dx, int *dy)
{
	float	i;

	i = 0;
	if (*dx > *dy)
	{
		i = (float)*dy / (float)*dx;
		*yi *= i;
	}
	else
	{
		i = (float)*dx / (float)*dy;
		*xi *= i;
	}
}

int	draw_line(t_mlx *cub , t_cord cord0, t_cord cord1)
{
	int	dx;
	int	dy;
	float	xi;
	float	yi;

	xi = direction(cord0.x, cord1.x);
	yi = direction(cord0.y, cord1.y);
	dx = fabs(cord1.x - cord0.x);
	dy = fabs(cord1.y - cord0.y);
	calculate_slope(&xi, &yi, &dx, &dy);
	while (dx > 0 || dy > 0)
	{
		if (cord0.x < WIDTH && cord0.y < HEIGHT)
			mlx_pixel_put(cub->mlx, cub->win, cord0.x, cord0.y, 0xFFFFFF);
		cord0.x += xi * (cord0.x != cord1.x);
		cord0.y += yi * (cord0.y != cord1.y);
		dx--;
		dy--;
	}
	return (0);
}
