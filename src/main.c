#include "../includes/cube3d.h"
#include <signal.h>

void sig_handle(int signum) {
	if (signum == SIGABRT) {}
}

int	main(void)
{
	t_mlx	cub;

	signal(SIGABRT, sig_handle);
	signal(6, sig_handle);

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "Cube3D");
	if (draw_cube(&cub) == -1)
		return (-1);
	// draw_grid_x(&cub, 50);
	// draw_grid_y(&cub, 50);
	mlx_loop(cub.mlx);
	return (0);
}

