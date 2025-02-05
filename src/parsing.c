#include "so_long.h"

int	map_getsize(char **argv, t_map *map)
{
	int		fd;
	char	*str;
	int		len;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)))
	{
		//printf("getting lenght\n");
		len = ft_strlen(str) - 1;
		if (map->width == 0)
			map->width = len;
		if (map->width < len || map->width > len)
        {
            //printf("trop long qque part");
			return (1);
        }
		map->height++;
		free(str);
	}
	close(fd);
	if (map->height == map->width)
	{
		//printf("carre mon reuf");
		return (1);
	}
	else
		return (0);
}

int	map_alloc(t_map *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc((map->height + 1) * sizeof(char *));
	// printf("first malloc\n");
	if (!map->map)
		return (1);
	while (i < map->height)
	{
		map->map[i] = malloc((map->width + 1) * sizeof(char));
		// printf("second malloc\n");
		if (!map->map[i])
			return (1);
		i++;
	}
	return (0);
}

int	map_check(t_map *map)
{
	map->y = 0;
	map->x = 0;
	// printf("height %d\n", map->height);
	// printf("width %d\n", map->width);
	// printf("map->x value %d\n", map->x);
	// printf("map->y value %d\n", map->y);
	while (map->y < map->width)
	{
		// printf("map->map[0][map->y] value : %c || & y value : %d\n",
			// map->map[0][map->y], map->y);
		//printf("map->map[map->height][map->y] value %c\n-\n", map->map[map->height
			// - 1][map->y]);
		if (map->map[0][map->y] != '1' || map->map[map->height
			- 1][map->y] != '1')
			return (1);
		map->y++;
	}
	map->y = 0;
	while (map->x < map->height)
	{
		//printf("map->map[map->x][0] value : %c || & x value : %d\n",
			// map->map[map->x][0], map->x);
		//printf("map->map[map->x][map->width] value %c\n-\n",
			// map->map[map->x][map->width - 1]);
		if (map->map[map->x][0] != '1' || map->map[map->x][map->width
			- 1] != '1')
			return (1);
		map->x++;
	}
	map->x = 0;
	map->y = 0;
	return (0);
}
// printf("map->map[0][map->y] value %c\n", map->map[0][1]);
// printf("map->map[0][map->y] value %c\n", map->map[0][2]);
// printf("map->map[0][map->y] value %c\n", map->map[0][3]);
// printf("map->map[0][map->y] value %c\n", map->map[0][4]);
// printf("map->map[0][map->y] value %c\n", map->map[0][5]);
int	map_copy(char **argv, t_map *map)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		while (str[map->y] != '\0' && str[map->y] != '\n')
		{
			map->map[map->x][map->y] = str[map->y];
			map->y++;
		}
		// printf("%s", map->map[map->x]);
		// printf("\n");
		free(str);
		map->y = 0;
		map->x++;
	}
	close(fd);
	map->x = 0;
	map->y = 0;
	return (0);
}

int	map_image(t_map *map, t_data *data)
{
	while (map->x < map->height)
	{
		while (map->y < map->width)
		{
			if (map->map[map->x][map->y] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->wall, map->y
					* 120, map->x * 120);
			}
			if (map->map[map->x][map->y] == '0')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->empty,
					map->y * 120, map->x * 120);
			}
			if (map->map[map->x][map->y] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->item, map->y
					* 120, map->x * 120);
			}
			if (map->map[map->x][map->y] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->oexit,
					map->y * 120, map->x * 120);
			}
			if (map->map[map->x][map->y] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->chacha,
					map->y * 120, map->x * 120);
			}
			map->y++;
		}
		map->y = 0;
		map->x++;
	}
	return (0);
}
