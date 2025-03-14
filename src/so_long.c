/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:53 by teatime           #+#    #+#             */
/*   Updated: 2025/03/14 17:41:21 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong		*sl;
	const t_funcptr	fptr = (t_funcptr)put_all_image;

	sl = ft_calloc(1, sizeof(t_solong));
	if (!sl)
		return (1);
	struct_initialisation(sl);
	valid_argument(argc, argv, sl);
	map_initialisation(argv, sl);
	win_initialisation(sl);
	mlx_key_hook(sl->data->win, key_hook, sl);
	printf("x :%d\n", sl->map->x);
	mlx_expose_hook(sl->data->win, fptr, sl);
	mlx_hook(sl->data->win, 17, 1L << 0, free_destroy, sl);
	mlx_loop(sl->data->mlx);
	return (0);
}

void	struct_initialisation(t_solong *sl)
{
	sl->map = ft_calloc(1, sizeof(t_map));
	if (!sl->map)
		free_exit(sl, "Error\nFailed struct init\n", EXIT_FAILURE);
	sl->pos = ft_calloc(1, sizeof(t_pos));
	if (!sl->pos)
		free_exit(sl, "Error\nFailed struct init\n", EXIT_FAILURE);
	sl->data = ft_calloc(1, sizeof(t_data));
	if (!sl->data)
		free_exit(sl, "Error\nFailed struct init\n", EXIT_FAILURE);
	sl->count = ft_calloc(1, sizeof(t_count));
	if (!sl->count)
		free_exit(sl, "Error\nFailed struct init\n", EXIT_FAILURE);
	sl->sprite = ft_calloc(1, sizeof(t_sprite));
	if (!sl->sprite)
		free_exit(sl, "Error\nFailed struct init\n", EXIT_FAILURE);
	sl->hud = ft_calloc(1, sizeof(t_hud));
	if (!sl->hud)
		free_exit(sl, "Error\nFailed struct init\n", EXIT_FAILURE);
}

void	map_initialisation(char **argv, t_solong *sl)
{
	if (map_getsize(argv, sl) == 1)
		free_exit(sl, "Error\nWrong size\n", EXIT_FAILURE);
	if (map_alloc(sl) == 1)
		free_exit(sl, "Error\nMalloc Error", EXIT_FAILURE);
	if (map_copy(argv, sl, sl->map) == 1)
		free_exit(sl, "Error\nWrong fd", EXIT_FAILURE);
	if (map_charcheck(sl->map) == 1)
		free_exit(sl, "Error\nInvalid char\n", EXIT_FAILURE);
	if (map_wallcheck(sl->map) == 1)
		free_exit(sl, "Error\nHole in the wall\n", EXIT_FAILURE);
	if (map_itemcheck(sl) == 1)
		free_exit(sl, "Error\nWrong parameters\n", EXIT_FAILURE);
	if (map_pathcheck(sl) == 1)
		free_exit(sl, "Error\nGame is rigged you can't win\n", EXIT_FAILURE);
}

void	win_initialisation(t_solong *sl)
{
	sl->data->mlx = mlx_init();
	if (sl->data->mlx == NULL)
		free_exit(sl, "Error\nMlx library initialisation failed\n",
			EXIT_FAILURE);
	if (load_image(sl) == 1)
		free_exit(sl, "Error\nNo image file or wrong extension\n",
			EXIT_FAILURE);
	sl->data->win = mlx_new_window(sl->data->mlx, 120 * sl->map->width, 120
			* sl->map->height, "so_long");
	if (sl->data->win == NULL)
		free_exit(sl, "Error\nWindow instance creation failed\n", EXIT_FAILURE);
	put_all_image(sl);
	display_hud(sl);
}

void	valid_argument(int argc, char **argv, t_solong *sl)
{
	char	*str;
	int		fd;

	if (argc != 2)
		free_exit(sl, "Error\nWrong number of arguments", EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free_exit(sl, "Error\nFile doesn't exist, or no permission\n",
			EXIT_FAILURE);
	}
	str = ft_strrchr(argv[1], '.');
	if (str == NULL)
		free_exit(sl, "Error\nNo extension", EXIT_FAILURE);
	if (ft_strncmp(str, ".ber", 5) != 0)
		free_exit(sl, "Error\nWrong file extension", EXIT_FAILURE);
}
