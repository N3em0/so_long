#include "so_long.h"

int	key_hook(int keycode, t_solong *sl)
{
	// if (keycode == 119)
	// printf("pressed up\n");
	// else if (keycode == 115)
	// printf("pressed down\n");
	if (keycode == 65307)
		ciao(sl);
	// printf("keycode : %d\n", keycode);
	return (0);
}

int	ciao(t_solong *sl)
{
	if (sl->sprite->chacha)
		mlx_destroy_image(sl->data->mlx, sl->sprite->chacha);
	if (sl->sprite->wall)
		mlx_destroy_image(sl->data->mlx, sl->sprite->wall);
	if (sl->sprite->empty)
		mlx_destroy_image(sl->data->mlx, sl->sprite->empty);
	if (sl->sprite->cexit)
		mlx_destroy_image(sl->data->mlx, sl->sprite->cexit);
	if (sl->sprite->oexit)
		mlx_destroy_image(sl->data->mlx, sl->sprite->oexit);
	if (sl->sprite->loot)
		mlx_destroy_image(sl->data->mlx, sl->sprite->loot);
	if (sl->data->win && sl->data->mlx)
		mlx_destroy_window(sl->data->mlx, sl->data->win);
	if (sl->data->mlx)
	{
		mlx_destroy_display(sl->data->mlx);
		free(sl->data->mlx);
	}
	free_exit(NULL, sl, 0);
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
