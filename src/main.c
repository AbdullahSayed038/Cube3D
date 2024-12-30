#include "../includes/cube3d.h"
#include <signal.h>

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Cube3D");
	if (draw_cube(&mlx, 10) == -1)
		return (-1);
	mlx_loop(mlx.mlx);
	return (0);
}

