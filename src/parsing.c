#include "so_long.h"

int	map_getsize(char **argv, t_solong *sl)
{
	int		fd;
	char	*str;
	int		len;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)))
	{
		len = ft_strlen(str) - 1;
		if (sl->map->width == 0)
			sl->map->width = len;
		if (sl->map->width < len || sl->map->width > len)
		{
			return (free(str), 1);
		}
		sl->map->height++;
		free(str);
	}
	printf("height %d\n", sl->map->height);
	printf("width %d\n", sl->map->width);
	close(fd);
	return (0);
}

int	map_alloc(t_solong *sl)
{
	int	i;

	i = 0;
	sl->map->map = (char **)malloc((sl->map->height) * sizeof(char *));
	if (!sl->map->map)
		return (1);
	while (i < sl->map->height)
	{
		sl->map->map[i] = malloc((sl->map->width + 1) * sizeof(char));
		if (!sl->map->map[i])
			return (1);
		i++;
	}
	return (0);
}

int	map_copy(char **argv, t_solong *sl)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		while (str[sl->map->y] != '\0' && str[sl->map->y] != '\n')
		{
			sl->map->map[sl->map->x][sl->map->y] = str[sl->map->y];
			sl->map->y++;
		}
		sl->map->map[sl->map->x][sl->map->y] = '\0';
		printf("%s", sl->map->map[sl->map->x]);
		printf("\n");
		free(str);
		sl->map->y = 0;
		sl->map->x++;
	}
	close(fd);
	sl->map->x = 0;
	sl->map->y = 0;
	return (0);
}
int	map_wallcheck(t_solong *sl)
{
	while (sl->map->y < sl->map->width)
	{
		if (sl->map->map[0][sl->map->y] != '1' || sl->map->map[sl->map->height
			- 1][sl->map->y] != '1')
			return (1);
		sl->map->y++;
	}
	sl->map->y = 0;
	while (sl->map->x < sl->map->height)
	{
		if (sl->map->map[sl->map->x][0] != '1'
			|| sl->map->map[sl->map->x][sl->map->width - 1] != '1')
			return (1);
		sl->map->x++;
	}
	sl->map->x = 0;
	sl->map->y = 0;
	return (0);
}
int	map_itemcheck(t_solong *sl)
{
	while (sl->map->x < sl->map->height)
	{
		while (sl->map->map[sl->map->x][sl->map->y] != '\0')
		{
			if (sl->map->map[sl->map->x][sl->map->y] == 'P')
			{
				sl->cpos->cy = sl->map->y;
				sl->cpos->cx = sl->map->x;
				sl->count->chachac += 1;
			}
			if (sl->map->map[sl->map->x][sl->map->y] == 'C')
				sl->count->lootc += 1;
			if (sl->map->map[sl->map->x][sl->map->y] == 'E')
				sl->count->exitc += 1;
			sl->map->y++;
		}
		sl->map->y = 0;
		sl->map->x++;
	}
	if (sl->count->chachac != 1 || sl->count->lootc < 1
		|| sl->count->exitc != 1)
		return (1);
	sl->map->x = 0;
	sl->map->y = 0;
	return (0);
}

int	map_loadimage(t_solong *sl)
{
	int	img_width;
	int	img_height;

	sl->sprite->chacha = mlx_xpm_file_to_image(sl->data->mlx, "img/char.xpm",
			&img_width, &img_height);
	sl->sprite->wall = mlx_xpm_file_to_image(sl->data->mlx, "img/wall.xpm",
			&img_width, &img_height);
	sl->sprite->empty = mlx_xpm_file_to_image(sl->data->mlx, "img/empty.xpm",
			&img_width, &img_height);
	sl->sprite->loot = mlx_xpm_file_to_image(sl->data->mlx, "img/c.xpm",
			&img_width, &img_height);
	sl->sprite->cexit = mlx_xpm_file_to_image(sl->data->mlx, "img/cexit.xpm",
			&img_width, &img_height);
	sl->sprite->oexit = mlx_xpm_file_to_image(sl->data->mlx, "img/oexit.xpm",
			&img_width, &img_height);
	if (!sl->sprite->chacha || !sl->sprite->wall || !sl->sprite->loot
		|| !sl->sprite->cexit || !sl->sprite->oexit)
		return (1);
	return (0);
}

void	map_put_image(t_solong *sl)
{
	if (sl->map->map[sl->map->x][sl->map->y] == '1')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->wall,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == '0')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->empty,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == 'C')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->loot,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == 'E')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->oexit,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == 'P')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win,
			sl->sprite->chacha, sl->map->y * 120, sl->map->x * 120);
	}
}

int	map_put_all_image(t_solong *sl)
{
	while (sl->map->x < sl->map->height)
	{
		while (sl->map->y < sl->map->width)
		{
			map_put_image(sl);
			sl->map->y++;
		}
		sl->map->y = 0;
		sl->map->x++;
	}
	return (0);
}
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->map)
	{
		while (i < map->height)
			free(map->map[i++]);
		free(map->map);
	}
}

void	free_sl(t_solong *sl)
{
	if (sl->sprite)
		free(sl->sprite);
	if (sl->count)
		free(sl->count);
	if (sl->data)
		free(sl->data);
	if (sl->cpos)
		free(sl->cpos);
	if (sl->map)
		free(sl->map);
	free(sl);
}
void	free_exit(char *str, t_solong *sl, int ret)
{
	if (sl)
	{
		free_map(sl->map);
		free_sl(sl);
	}
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(ret);
}

void	map_initialisation(char **argv, t_solong *sl)
{
	if (map_getsize(argv, sl) == 1)
		free_exit("Wrong size\n", sl, 1);
	if (map_alloc(sl) == 1)
		free_exit("Malloc Error", sl, 1);
	if (map_copy(argv, sl) == 1)
		free_exit(NULL, sl, 1);
	if (map_wallcheck(sl) == 1)
		free_exit("Hole in the wall\n", sl, 1);
	if (map_itemcheck(sl) == 1)
		free_exit("Wrong parameters\n", sl, 1);
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
