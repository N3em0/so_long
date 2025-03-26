/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:43 by teatime           #+#    #+#             */
/*   Updated: 2025/03/26 19:31:53 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_getsize(char **argv, t_solong *sl)
{
	int		fd;
	char	*str;
	int		len;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
		return (1);
	while (str)
	{
		len = ft_strlen(str) - 1;
		if (sl->map->width == 0)
			sl->map->width = len;
		if (sl->map->width < len || sl->map->width > len
			|| sl->map->height >= 17 || sl->map->width > 32)
		{
			close (fd);
			free(str);
			return (1);
		}
		sl->map->height++;
		free(str);
		str = get_next_line(fd);
	}
	return (close(fd), 0);
}

int	map_alloc(t_solong *sl)
{
	int	i;

	i = 0;
	sl->map->map = NULL;//(char **)malloc((sl->map->height) * sizeof(char *));
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

int	map_copy(char **argv, t_solong *sl, t_map *map)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		while (str[map->y] != '\0' && str[map->y] != '\n')
		{
			if (str[map->y] == 'E')
				map_get_exitpos(sl, map->x, map->y);
			if (str[map->y] == 'P')
				map_get_playerpos(sl, map->x, map->y);
			map->map[map->x][map->y] = str[map->y];
			map->mapcopy[map->x][map->y++] = map->map[map->x][map->y];
		}
		map->map[map->x][map->y] = '\0';
		map->mapcopy[map->x++][map->y] = '\0';
		free(str);
		str = get_next_line(fd);
		map->y = 0;
	}
	sl->map->x = 0;
	sl->map->y = 0;
	return (close(fd), 0);
}

void	map_get_exitpos(t_solong *sl, int x, int y)
{
	sl->pos->ex = x;
	sl->pos->ey = y;
}

void	map_get_playerpos(t_solong *sl, int x, int y)
{
	sl->pos->px = x;
	sl->pos->py = y;
}
