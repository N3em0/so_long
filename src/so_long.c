#include "so_long.h"

int	key_hook(int keycode, t_solong *sl)
{
	//printf("sl->map->height value dans key_hook %d\n", sl->map->height);
	//if (keycode == 119)
		//printf("pressed up\n");
	//else if (keycode == 115)
		//printf("pressed down\n");
	if (keycode == 65307)
		ciao(sl);
	//printf("keycode : %d\n", keycode);
	return (0);
}

int	ciao(t_solong *sl)
{
	//printf("allo ?\n");
	if (sl->sprite->chacha)
		mlx_destroy_image(sl->data->mlx, sl->sprite->chacha);
	if (sl->sprite->wall)
		mlx_destroy_image(sl->data->mlx, sl->sprite->wall);
	if (sl->sprite->empty)
		mlx_destroy_image(sl->data->mlx, sl->sprite->empty);
	if (sl->sprite->oexit)
		mlx_destroy_image(sl->data->mlx, sl->sprite->oexit);
	if (sl->sprite->item)
		mlx_destroy_image(sl->data->mlx, sl->sprite->item);
	if (sl->data->win && sl->data->mlx)
		mlx_destroy_window(sl->data->mlx, sl->data->win);
	if (sl->data->mlx)
	{
		mlx_destroy_display(sl->data->mlx);
		free(sl->data->mlx);
	}
	free_map(sl);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_solong	*sl;
	int			img_width;
	int			img_height;
	int			i;

	sl = ft_calloc(1, sizeof(t_solong));
	i = 0;
	if (argc != 2)
		return (1);
	sl->map = ft_calloc(1, sizeof(t_map));
	sl->data = ft_calloc(1, sizeof(t_data));
	sl->sprite = ft_calloc(1, sizeof(t_sprite));
	//printf("sl->map->widthcaca : %d\n", sl->map->height);
	if (map_getsize(argv, sl) == 1)
	{
		free_map(sl);//printf("trop long mon reuf\n");
		return (1);
	}
	if (map_alloc(sl) == 1)
	{
		free_map(sl);
		return (1);
	}
	if (map_copy(argv, sl) == 1)
	{
		free_map(sl);
		return (1);
	}
	if (map_check(sl) == 1)
	{
		free_map(sl);
		//printf("y'a un trou dans le mur\n");
		return (1);
	}
	//printf("plop\n");
	sl->data->mlx = mlx_init();
	//printf("plop\n");
	sl->data->win = mlx_new_window(sl->data->mlx, 120 * sl->map->width, 120
			* sl->map->height, "merci le delegue");
	sl->sprite->chacha = mlx_xpm_file_to_image(sl->data->mlx, "img/char.xpm",
			&img_width, &img_height);
	sl->sprite->wall = mlx_xpm_file_to_image(sl->data->mlx, "img/wall.xpm",
			&img_width, &img_height);
	sl->sprite->empty = mlx_xpm_file_to_image(sl->data->mlx, "img/empty.xpm",
			&img_width, &img_height);
	sl->sprite->item = mlx_xpm_file_to_image(sl->data->mlx, "img/c.xpm",
			&img_width, &img_height);
	sl->sprite->oexit = mlx_xpm_file_to_image(sl->data->mlx, "img/open.xpm",
			&img_width, &img_height);
	map_image(sl);
	mlx_hook(sl->data->win, 17, 1L << 0, ciao, sl);
	mlx_key_hook(sl->data->win, key_hook, sl);
	mlx_loop(sl->data->mlx);
}
