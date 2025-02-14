/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:43 by teatime           #+#    #+#             */
/*   Updated: 2025/02/14 18:50:48 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_getsize(char **argv, t_solong *sl)
{
	int		fd;
	char	*str;
	int		len;

	fd = open(argv[1], O_RDONLY);
	while ((str = get_next_line(fd)))
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
	}
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
			if (str[sl->map->y] == 'E')
				map_get_exitpos(sl, sl->map->x, sl->map->y);
			if (str[sl->map->y] == 'P')
				map_get_playerpos(sl, sl->map->x, sl->map->y);
			sl->map->map[sl->map->x][sl->map->y] = str[sl->map->y];
			sl->map->mapcopy[sl->map->x][sl->map->y] = sl->map->map[sl->map->x][sl->map->y];
			sl->map->y++;
		}
		sl->map->map[sl->map->x][sl->map->y] = '\0';
		sl->map->mapcopy[sl->map->x++][sl->map->y] = '\0';
		free(str);
		sl->map->y = 0;
	}
	close(fd);
	sl->map->x = 0;
	sl->map->y = 0;
	return (0);
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
