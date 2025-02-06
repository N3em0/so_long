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
	close(fd);
	return (0);
}

int	map_alloc(t_solong *sl)
{
	int	i;

	i = 0;
	sl->map->map = (char **)malloc((sl->map->height + 1) * sizeof(char *));
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

int	map_check(t_solong *sl)
{
	sl->map->y = 0;
	sl->map->x = 0;
	//printf("height %d\n", sl->map->height);
	// printf("width %d\n", sl->map->width);
	// printf("map->x value %d\n", sl->map->x);
	// printf("map->y value %d\n", sl->map->y);
	while (sl->map->y < sl->map->width)
	{
		// printf("map->map[0][map->y] value : %c || & y value : %d\n",
		// sl->map->map[0][sl->map->y], sl->map->y);
		// printf("map->map[map->height][map->y] value %c\n-\n",
		// sl->map->map[sl->map->height - 1][sl->map->y]);
		if (sl->map->map[0][sl->map->y] != '1' || sl->map->map[sl->map->height
			- 1][sl->map->y] != '1')
			return (1);
		sl->map->y++;
	}
	sl->map->y = 0;
	while (sl->map->x < sl->map->height)
	{
		// printf("map->map[map->x][0] value : %c || & x value : %d\n",
		// map->map[map->x][0], map->x);
		// printf("map->map[map->x][map->width] value %c\n-\n",
		// map->map[map->x][map->width - 1]);
		if (sl->map->map[sl->map->x][0] != '1'
			|| sl->map->map[sl->map->x][sl->map->width - 1] != '1')
			return (1);
		sl->map->x++;
	}
	sl->map->x = 0;
	sl->map->y = 0;
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
		//printf("%s", sl->map->map[sl->map->x]);
		//printf("\n");
		free(str);
		sl->map->y = 0;
		sl->map->x++;
	}
	close(fd);
	sl->map->x = 0;
	sl->map->y = 0;
	// printf("map->map[0][map->y] value %s\n", map->map[0]);
	// printf("map->map[0][map->y] value %s\n", map->map[1]);
	// printf("map->map[0][map->y] value %s\n", map->map[2]);
	// printf("map->map[0][map->y] value %s\n", map->map[3]);
	// printf("map->map[0][map->y] value %s\n", map->map[4]);
	return (0);
}

int	map_image(t_solong *sl)
{
	while (sl->map->x < sl->map->height)
	{
		while (sl->map->y < sl->map->width)
		{
			if (sl->map->map[sl->map->x][sl->map->y] == '1')
			{
				mlx_put_image_to_window(sl->data->mlx, sl->data->win,
					sl->sprite->wall, sl->map->y * 120, sl->map->x * 120);
			}
			if (sl->map->map[sl->map->x][sl->map->y] == '0')
			{
				mlx_put_image_to_window(sl->data->mlx, sl->data->win,
					sl->sprite->empty, sl->map->y * 120, sl->map->x * 120);
			}
			if (sl->map->map[sl->map->x][sl->map->y] == 'C')
			{
				mlx_put_image_to_window(sl->data->mlx, sl->data->win,
					sl->sprite->item, sl->map->y * 120, sl->map->x * 120);
			}
			if (sl->map->map[sl->map->x][sl->map->y] == 'E')
			{
				mlx_put_image_to_window(sl->data->mlx, sl->data->win,
					sl->sprite->oexit, sl->map->y * 120, sl->map->x * 120);
			}
			if (sl->map->map[sl->map->x][sl->map->y] == 'P')
			{
				mlx_put_image_to_window(sl->data->mlx, sl->data->win,
					sl->sprite->chacha, sl->map->y * 120, sl->map->x * 120);
			}
			sl->map->y++;
		}
		sl->map->y = 0;
		sl->map->x++;
	}
	return (0);
}
void	free_map(t_solong *sl)
{
	int	i;

	i = 0;
	//printf("sl->data height value dans free_map %d\n", sl->map->height);
	while (i < sl->map->height)
		free(sl->map->map[i++]);
	free(sl->map->map);
	free(sl->sprite);
	free(sl->data);
	free(sl->map);
	free(sl);
	return ;
}
