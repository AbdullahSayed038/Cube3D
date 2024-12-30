#include "../includes/cube3d.h"

void	init_face(t_cord *face, t_cord center, int size, int side)
{
	int z;

	z = 1;
	if (side == FRONT)
		z *= -1;
	face[0].x = center.x - size;
	face[0].y = center.y + size;
	face[0].z = center.z + size * z;
	face[1].x = center.x + size;
	face[1].y = center.y + size;
	face[1].z = center.z + size * z;
	face[2].x = center.x - size;
	face[2].y = center.y - size;
	face[2].z = center.z + size * z;
	face[3].x = center.x + size;
	face[3].y = center.y - size;
	face[3].z = center.z + size * z;
}

int	DepthCords(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if ((cube->Bface[i].z + FOV) == 0)
			return (-1);
		cube->Bface[i].x = cube->Bface[i].x / (cube->Bface[i].z + FOV);
	}
		i = -1;
	while (++i < 4)
	{
		if ((cube->Fface[i].z + FOV) == 0)
			return (-1);
		cube->Fface[i].x = cube->Fface[i].x / (cube->Fface[i].z + FOV);
	}
	return (0);
}

void	connect_cube(t_mlx *mlx, t_cube cube)
{
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
	draw_line(mlx, , );
}

int	draw_cube(t_mlx *mlx, int size)
{
	t_cube cube;

	init_cord(&cube.center, WIDTH / 2, HEIGHT / 2, 0);
	init_face(cube.Bface, cube.center, size * PIXEL, BACK);
	init_face(cube.Fface, cube.center, size * PIXEL, FRONT);
	if (DepthCords(&cube) == -1)
		return (-1);
	connect_cube(&mlx, cube);

}
