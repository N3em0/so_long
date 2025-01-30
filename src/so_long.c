#include "so_long.h"
#include <stdlib.h>

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
}			t_data;

int	ciao(t_data *data)
{
	printf("allo ?");
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 119)
		printf("pressed up\n");
	else if (keycode == 115)
		printf("pressed down\n");
	else if (keycode == 65307)
		ciao(data);
	printf("keycode : %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_data	img;
	int		img_width;
	int		img_height;

	img.mlx = mlx_init();
	printf("salut 1\n");
	img.win = mlx_new_window(img.mlx, 1920, 1080, "yoyoyoyo");
	printf("salut 2\n");
	img.img = mlx_xpm_file_to_image(img.mlx, "img/char.xpm", &img_width,
			&img_height);
	printf("salut 3\n");
	mlx_put_image_to_window(img.mlx, img.win, img.img, 965, 540);
	mlx_hook(img.win, 17, 1L << 0, ciao, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop(img.mlx);
}
