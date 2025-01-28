#include "so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		y;
	int		x;
	int	i;
	int	j;
	int	min;
	int	max;

	y = 0;
	x = 0;
	i = 0;
	j = 0;
	min = 0;
	max = 20;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "pascaca");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// while (j <= 10)
	// {
	while (i <= 20)
	{
		while (x <= max)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		max -= 1;
		min += 1;
		x = min;
		i++;
		y++;
	}
	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// i = 0;
	// while (i <= 20)
	// {
	// 		while (x >= min)
	// 		{
	// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 			x++;
	// 		}
	// 		max += 1;
	// 		min -= 1;
	// 		x = min;
	// 		i++;
	// 		y++;
	// }
	// 	x = 0;
	// 	i = 0;
	// 	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 	y++;
	// 	j++;
	// }
	// my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
	// my_mlx_pixel_put(&img, -1, 1, 0x00FF0000);
	// my_mlx_pixel_put(&img, 0, 1, 0x00FF0000);
	// my_mlx_pixel_put(&img, 1, 1, 0x00FF0000);
	// my_mlx_pixel_put(&img, -2, 2, 0x00FF0000);
	// my_mlx_pixel_put(&img, -1, 2, 0x00FF0000);
	// my_mlx_pixel_put(&img, 0, 2, 0x00FF0000);
	// my_mlx_pixel_put(&img, 1, 2, 0x00FF0000);
	// my_mlx_pixel_put(&img, 2, 2, 0x00FF0000);
	// my_mlx_pixel_put(&img, 1, 9, 0x00FF0000);
	// my_mlx_pixel_put(&img, -2, 3, 0x00FF0000);
	// my_mlx_pixel_put(&img, -1, 3, 0x00FF0000);
	// my_mlx_pixel_put(&img, 0, 3, 0x00FF0000);
	// my_mlx_pixel_put(&img, 1, 3, 0x00FF0000);
	// my_mlx_pixel_put(&img, 2, 3, 0x00FF0000);
	// my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 960, 540);
	printf("salut\n");
	printf("x : %d\n", x);
	x++;
	// mlx_string_put(mlx, mlx_win, 960, 540, 0xffffff, "caca");
	mlx_loop(mlx);
}
