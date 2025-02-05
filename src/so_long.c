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
	int		i;
	t_map	map;

	i = 0;
	printf("map height value %d\n", map.height);
	while (i < map.height)
	{
		printf("ca free la en gros\n");
		free(map.map[i]);
		i++;
	}
	free(map.map);
	printf("allo ?\n");
	if (data->chacha)
	{
		mlx_destroy_image(data->mlx, data->chacha);
		// free(data->chacha);
	}
	if (data->wall)
	{
		mlx_destroy_image(data->mlx, data->wall);
		// free(data->wall);
	}
	if (data->empty)
	{
		mlx_destroy_image(data->mlx, data->empty);
		// free(data->empty);
	}
	if (data->oexit)
	{
		mlx_destroy_image(data->mlx, data->oexit);
		// free(data->oexit);
	}
	if (data->item)
	{
		mlx_destroy_image(data->mlx, data->item);
		// free(data->item);
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		// free(data->win);
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		// free(data->mlx);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	int		img_width;
	int		img_height;
	int		i;

	i = 0;
	if (argc != 2)
		return (1);
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&data, 0, sizeof(t_data));
	if (map_getsize(argv, &map) == 1)
		return (1);
	if (map_alloc(&map) == 1)
	{
		while (i < map.height)
		{
			free(map.map[i]);
			i++;
		}
		free(map.map);
		return (1);
	}
	if (map_copy(argv, &map) == 1)
	{
		while (i < map.height)
		{
			free(map.map[i]);
			i++;
		}
		free(map.map);
		return (1);
	}
	if (map_check(&map) == 1)
	{
		while (i < map.height)
		{
			free(map.map[i]);
			i++;
		}
		free(map.map);
		// printf("y'a un trou dans le mur");
		return (1);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 120 * map.width, 120 * map.height,
			"salut");
	data.chacha = mlx_xpm_file_to_image(data.mlx, "img/char.xpm", &img_width,
			&img_height);
	data.wall = mlx_xpm_file_to_image(data.mlx, "img/wall.xpm", &img_width,
			&img_height);
	data.empty = mlx_xpm_file_to_image(data.mlx, "img/empty.xpm", &img_width,
			&img_height);
	data.item = mlx_xpm_file_to_image(data.mlx, "img/c.xpm", &img_width,
			&img_height);
	data.oexit = mlx_xpm_file_to_image(data.mlx, "img/open.xpm", &img_width,
			&img_height);
	map_image(&map, &data);
	mlx_hook(data.win, 17, 1L << 0, ciao, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
