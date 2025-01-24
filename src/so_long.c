#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "caca");
	mlx_string_put(mlx, mlx_win, 960, 540, 0xffffff, "caca");
	mlx_loop(mlx);
}
