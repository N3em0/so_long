#include "so_long.h"

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
	win_initialisation(sl);
	mlx_hook(sl->data->win, 17, 1L << 0, &mlx_loop_end, sl);
	mlx_key_hook(sl->data->win, key_hook, sl);
	mlx_loop(sl->data->mlx);
	free_exit(NULL, sl, 0);
	return (0);
}

void	struct_initialisation(t_solong *sl)
{
	sl->map = ft_calloc(1, sizeof(t_map));
	if (!sl->map)
		free_exit("Error\nFailed struct init\n", sl, 1);
	sl->pos = ft_calloc(1, sizeof(t_pos));
	if (!sl->pos)
		free_exit("Error\nFailed struct init\n", sl, 1);
	sl->data = ft_calloc(1, sizeof(t_data));
	if (!sl->data)
		free_exit("Error\nFailed struct init\n", sl, 1);
	sl->count = ft_calloc(1, sizeof(t_count));
	if (!sl->count)
		free_exit("Error\nFailed struct init\n", sl, 1);
	sl->sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sl->sprite)
		free_exit("Error\nFailed struct init\n", sl, 1);
}

void	map_initialisation(char **argv, t_solong *sl)
{
	if (map_getsize(argv, sl) == 1)
		free_exit("Error\nWrong size\n", sl, 2);
	if (map_alloc(sl) == 1)
		free_exit("Error\nMalloc Error", sl, 2);
	if (map_copy(argv, sl) == 1)
		free_exit("Error\nWrong fd", sl, 2);
	if (map_charcheck(sl->map) == 1)
		free_exit("Error\nInvalid char\n", sl, 2);
	if (map_wallcheck(sl->map) == 1)
		free_exit("Error\nHole in the wall\n", sl, 2);
	if (map_itemcheck(sl) == 1)
		free_exit("Error\nWrong parameters\n", sl, 2);
	if (map_pathcheck(sl) == 1)
		free_exit("Error\nGame rigged you can't win\n", sl, 2);
}

void	win_initialisation(t_solong *sl)
{
	sl->data->mlx = mlx_init();
	if (sl->data->mlx == NULL)
		free_exit("Error\nmlx_init failed\n", sl, 2);
	if (load_image(sl) == 1)
		free_exit("Error\nWrong image\n", sl, 2);
	sl->data->win = mlx_new_window(sl->data->mlx, 120 * sl->map->width, 120
			* sl->map->height, "merci le delegue");
	if (sl->data->win == NULL)
		free_exit("Error\nmlx_new_window failed\n", sl, 2);
	put_all_image(sl);
	display_hud(sl);
}

// proteger argv != 2 // proteger si extension pas bonne
// get ex/ey && cx/cy a mettre dans la meme fonction ?
// faire une fonction pour copier la map dans une deuxieme copie (+ trouver un nom)
// gerer fermeture avec la croix
