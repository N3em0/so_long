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
	sl->pos = ft_calloc(1, sizeof(t_pos));
	if (!sl->pos)
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
//to do : 
// affichage steps quand jeu fini + collecte/collectable ?
// get ex/ey && cx/cy a mettre dans la meme fonction ?
// faire une fonction pour copier la map dans une deuxieme copie (+ trouver un nom)