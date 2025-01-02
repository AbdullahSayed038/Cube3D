#include "../includes/cube3d.h"

void	init_faceF(t_cord *face, t_cord center, int size)
{
	face[0].x = center.x - size;
	face[0].y = center.y + size;
	face[0].z = center.z - (size / 4);
	face[1].x = center.x + size;
	face[1].y = center.y + size;
	face[1].z = center.z - (size / 4);
	face[2].x = center.x - size;
	face[2].y = center.y - size;
	face[2].z = center.z - (size / 4);
	face[3].x = center.x + size;
	face[3].y = center.y - size;
	face[3].z = center.z - (size / 4);
}

void	init_faceB(t_cord *face, t_cord center, int size)
{
	face[0].x = center.x - size;
	face[0].y = center.y + size;
	face[0].z = center.z + (size / 4);
	face[1].x = center.x + size;
	face[1].y = center.y + size;
	face[1].z = center.z + (size / 4);
	face[2].x = center.x - size;
	face[2].y = center.y - size;
	face[2].z = center.z + (size / 4);
	face[3].x = center.x + size;
	face[3].y = center.y - size;
	face[3].z = center.z + (size / 4);
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
	i = -1;
	while (++i < 4)
		cube->Bface[i].y = cube->Bface[i].y / (cube->Bface[i].z + FOV);
	i = -1;
	while (++i < 4)
		cube->Fface[i].y = cube->Fface[i].y / (cube->Fface[i].z + FOV);
	return (0);
}

void	print_cords(t_cord cord)
{
	printf("x = %f\n", cord.x);
	printf("y = %f\n", cord.y);
	printf("z = %f\n", cord.z);
}

void	print_face_cords(t_cube cube)
{
	int i = -1;
	while (++i < 4)
	{
		printf("BACK = ");
		print_cords(cube.Bface[i]);
	}
	i = -1;
	while (++i < 4)
	{
		printf("FRONT = ");
		print_cords(cube.Fface[i]);
	}
}

void	connect_cube(t_mlx *mlx, t_cube cube)
{
   // Connect edges of the back face (Bface)
    draw_line(mlx, cube.Bface[0], cube.Bface[1]); // Top edge
    draw_line(mlx, cube.Bface[1], cube.Bface[3]); // Right edge
    draw_line(mlx, cube.Bface[3], cube.Bface[2]); // Bottom edge
    draw_line(mlx, cube.Bface[2], cube.Bface[0]); // Left edge

    // Connect edges of the front face (Fface)
    draw_line(mlx, cube.Fface[0], cube.Fface[1]); // Top edge
    draw_line(mlx, cube.Fface[1], cube.Fface[3]); // Right edge
    draw_line(mlx, cube.Fface[3], cube.Fface[2]); // Bottom edge
    draw_line(mlx, cube.Fface[2], cube.Fface[0]); // Left edge

    // Connect corresponding vertices between Bface and Fface
    draw_line(mlx, cube.Bface[3], cube.Fface[0]); // Top-left
    draw_line(mlx, cube.Bface[1], cube.Fface[2]); // Top-right
    draw_line(mlx, cube.Bface[2], cube.Fface[1]); // Bottom-left
    draw_line(mlx, cube.Bface[0], cube.Fface[3]); // Bottom-right
}

int	draw_cube(t_mlx *mlx, int size)
{
	t_cube cube;
	int i;
	float SCALE_FACTOR;

	SCALE_FACTOR = fmin(WIDTH, HEIGHT) / (8 * size); // Adjust divisor for better scaling
	init_cord(&cube.center, WIDTH / 2, HEIGHT / 2, -FOV);
	init_faceB(cube.Bface, cube.center, (size * PIXEL) / 2);
	init_faceF(cube.Fface, cube.center, (size * PIXEL) / 2);
	if (DepthCords(&cube) == -1)
		return (-1);
	i = -1;
	while (++i < 4)
	{
		cube.Bface[i].x = cube.Bface[i].x * SCALE_FACTOR + WIDTH / 2;
		cube.Bface[i].y = cube.Bface[i].y * SCALE_FACTOR + HEIGHT / 2;
	}
	i = -1;
	while (++i < 4)
	{
		cube.Fface[i].x = cube.Fface[i].x * SCALE_FACTOR + WIDTH / 2;
		cube.Fface[i].y = cube.Fface[i].y * SCALE_FACTOR + HEIGHT / 2;
	}
	print_face_cords(cube);
	connect_cube(mlx, cube);
	return (0);
}
