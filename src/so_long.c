#include "so_long.h"

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

int	ciao(t_data *data)
{
	printf("allo ?");
	// if (data->img)
	// 	mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	int		img_width;
	int		img_height;

	(void)argc;
	if (argc != 2)
		return 0;
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&data, 0, sizeof(t_data));
	map_copy(argv, &map);
	printf("caca");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 120 * (map.width - 1), 120 * map.height, "salut");
	data.chacha = mlx_xpm_file_to_image(data.mlx, "img/char.xpm", &img_width, &img_height);
	data.wall = mlx_xpm_file_to_image(data.mlx, "img/wall.xpm", &img_width, &img_height);
	data.empty = mlx_xpm_file_to_image(data.mlx, "img/empty.xpm", &img_width, &img_height);
	data.item = mlx_xpm_file_to_image(data.mlx, "img/c.xpm", &img_width, &img_height);
	data.oexit = mlx_xpm_file_to_image(data.mlx, "img/open.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(data.mlx, data.win, data.item, map.x * 100, map.y * 100);
	// y++;
	// if (map.map[map->x][map->y] == '1')
	// 	mlx_put_image_to_window(data.mlx, data.win, data.empty, map.x * 100, map.y * 100);
	map_image(&map, &data);
	mlx_hook(data.win, 17, 1L << 0, ciao, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}