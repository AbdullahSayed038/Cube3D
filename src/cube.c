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

void	connect_dots(t_mlx *cub, t_cord *prime)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		draw_line(cub, prime[i], prime[(i + 1) % 4]);
		i += 2;
	}
}

void	scale_cords(t_cord *prime)
{
	int	i;

	i = -1;
	while (i++ < 4)
	{
		prime[i].x = (prime[i].x * (WIDTH / 2));
		prime[i].y = (prime[i].y * (HEIGHT / 2));
	}
}

int	draw_face(t_mlx *cub, t_cord *face)
{
	t_cord	prime[4];
	int		i;

	i = -1;
	while (i++ < 4)
		if (face[i].z + DEPTH == 0)
			return (-1);
	i = -1;
	while (i++ < 4)
	{
		prime[i].x = face[i].x / (face[i].z + DEPTH);
		prime[i].y = face[i].y / (face[i].z + DEPTH);
		prime[i].z = 0;
	}
	i = -1;
	scale_cords(prime);
	connect_dots(cub, prime);
	return (0);
}

int	draw_cube(t_mlx *cub)
{
	t_cube cube;

	init_cord(&cube.center, WIDTH / 2, HEIGHT / 2, 0);
	init_face(cube.Fface, cube.center, 1, FRONT);
	init_face(cube.Bface, cube.center, 1, BACK);
	if (draw_face(cub, cube.Fface) == -1)
		return (-1);
	printf("%s\n", "here");
	if (draw_face(cub, cube.Bface) == -1)
		return (-1);
	return (0);
}
