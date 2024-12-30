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
# define FOV 60
# define PIXEL 10

enum FACE
{
	FRONT,
	BACK,
};

typedef struct s_cord
{
	float	x;
	float	y;
	float	z;
}	t_cord;

typedef struct s_cube
{
	t_cord	center;
	t_cord	Fface[4];
	t_cord	Bface[4];
}	t_cube;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

//draw line
int		draw_line(t_mlx *cub , t_cord cord0, t_cord cord1);
float	direction(float d1, float d2);
void	init_cord(t_cord *cord, float x, float y, float z);
void	calculate_slope(float *xi, float *yi, int *dx, int *dy);

//draw grid
void	draw_grid_x(t_mlx *cub, int diff);
void	draw_grid_y(t_mlx *cub, int diff);

//draw cube
int		draw_cube(t_mlx *cub, int size);


#endif