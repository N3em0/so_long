#include "so_long.h"

int	key_hook(int keycode, t_solong *sl)
{
	if (keycode == 119)
	{
		if ((sl->cpos->cx > 0) && (sl->map->map[sl->cpos->cx - 1][sl->cpos->cy] != '1'))
		{
			sl->cpos->cx--;
			printf("%d\n", sl->cpos->cx);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win,
				sl->sprite->chacha, sl->cpos->cy * 120, sl->cpos->cx * 120);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->empty,
				(sl->cpos->cy) * 120, (sl->cpos->cx + 1) * 120);
		}
		printf("pressed up\n");
	}
	if (keycode == 115)
	{
		if ((sl->cpos->cx < sl->map->height) && (sl->map->map[sl->cpos->cx + 1][sl->cpos->cy] != '1'))
		{
			sl->cpos->cx++;
			printf("%d\n", sl->cpos->cx);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win,
				sl->sprite->chacha, sl->cpos->cy * 120, sl->cpos->cx * 120);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->empty,
				sl->cpos->cy * 120, (sl->cpos->cx - 1) * 120);
		}
		printf("pressed down\n");
	}
	if (keycode == 97) //left
	{
		if ((sl->cpos->cy > 0) && (sl->map->map[sl->cpos->cx][sl->cpos->cy - 1] != '1'))
		{
			sl->cpos->cy--;
			printf("%d\n", sl->cpos->cy);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win,
				sl->sprite->chacha, sl->cpos->cy * 120, sl->cpos->cx * 120);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->empty,
				(sl->cpos->cy + 1) * 120, sl->cpos->cx * 120);
		}
		printf("pressed left\n");
	}
	if (keycode == 100) // right
	{
		if ((sl->cpos->cy < sl->map->width - 1) && (sl->map->map[sl->cpos->cx][sl->cpos->cy + 1] != '1'))
		{
			sl->cpos->cy++;
			printf("%d\n", sl->cpos->cy);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win,
				sl->sprite->chacha, sl->cpos->cy * 120, sl->cpos->cx * 120);
			mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->empty,
				(sl->cpos->cy - 1) * 120, sl->cpos->cx * 120);
		}
		printf("pressed right\n");
	}
	else if (keycode == 65307)
		ciao(sl);
	printf("keycode : %d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_solong	*sl;

	if (argc != 2)
		return (1);
	sl = ft_calloc(1, sizeof(t_solong));
	if (!sl)
		return (1);
	struct_initialisation(sl);
	map_initialisation(argv, sl);
	sl->data->mlx = mlx_init();
	map_loadimage(sl);
	sl->data->win = mlx_new_window(sl->data->mlx, 120 * sl->map->width, 120
			* sl->map->height, "merci le delegue");
	map_put_all_image(sl);
	mlx_hook(sl->data->win, 17, 1L << 0, &mlx_loop_end, sl);
	mlx_key_hook(sl->data->win, key_hook, sl);
	mlx_loop(sl->data->mlx);
	ciao(sl);
	return (0);
}

void	struct_initialisation(t_solong *sl)
{
	sl->map = ft_calloc(1, sizeof(t_map));
	if (!sl->map)
	free_exit("Failed struct init\n", sl, 1);
	sl->cpos = ft_calloc(1, sizeof(t_cpos));
	if (!sl->cpos)
	free_exit("Failed struct init\n", sl, 1);
	sl->data = ft_calloc(1, sizeof(t_data));
	if (!sl->data)
	free_exit("Failed struct init\n", sl, 1);
	sl->count = ft_calloc(1, sizeof(t_count));
	if (!sl->count)
	free_exit("Failed struct init\n", sl, 1);
	sl->sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sl->sprite)
	free_exit("Failed struct init\n", sl, 1);
}
