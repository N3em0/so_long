#include "so_long.h"

void	map_initialisation(char **argv, t_solong *sl)
{
    if (map_getsize(argv, sl) == 1)
        free_exit("Wrong size\n", sl, 1);
    if (map_alloc(sl) == 1)
        free_exit("Malloc Error", sl, 1);
    if (map_copy(argv, sl) == 1)
        free_exit(NULL, sl, 1);
    if (map_charcheck(sl->map) == 1)
        free_exit("Invalid char\n", sl, 1);
    if (map_wallcheck(sl->map) == 1)
        free_exit("Hole in the wall\n", sl, 1);
    if (map_itemcheck(sl) == 1)
        free_exit("Wrong parameters\n", sl, 1);
    if (map_pathcheck(sl) == 1)
        free_exit("Game rigged you can't win\n", sl, 1);

}
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
    sl->map->mapcopy = (char **)malloc((sl->map->height) * sizeof(char *));
	if (!sl->map->map || !sl->map->mapcopy)
		return (1);
	while (i < sl->map->height)
	{
		sl->map->map[i] = malloc((sl->map->width + 1) * sizeof(char));
        sl->map->mapcopy[i] = malloc((sl->map->width + 1) * sizeof(char));
		if (!sl->map->map[i] || !sl->map->mapcopy[i])
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
            sl->map->mapcopy[sl->map->x][sl->map->y] = sl->map->map[sl->map->x][sl->map->y];
			sl->map->y++;
		}
		sl->map->map[sl->map->x][sl->map->y] = '\0';
        sl->map->mapcopy[sl->map->x][sl->map->y] = '\0';
		printf("%s || %s", sl->map->map[sl->map->x], sl->map->mapcopy[sl->map->x]);
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
