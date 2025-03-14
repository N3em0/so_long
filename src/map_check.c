/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:17 by teatime           #+#    #+#             */
/*   Updated: 2025/03/14 14:07:09 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_charcheck(t_map *map)
{
	while (map->x < map->height)
	{
		while (map->map[map->x][map->y] != '\0')
		{
			if (map->map[map->x][map->y] != 'P'
				&& map->map[map->x][map->y] != 'C'
				&& map->map[map->x][map->y] != 'E'
				&& map->map[map->x][map->y] != '0'
				&& map->map[map->x][map->y] != '1')
				return (1);
			map->y++;
		}
		map->y = 0;
		map->x++;
	}
	map->x = 0;
	map->y = 0;
	return (0);
}

int	map_wallcheck(t_map *map)
{
	while (map->y < map->width)
	{
		if (map->map[0][map->y] != '1' || map->map[map->height
			- 1][map->y] != '1')
			return (1);
		map->y++;
	}
	map->y = 0;
	while (map->x < map->height)
	{
		if (map->map[map->x][0] != '1' || map->map[map->x][map->width
			- 1] != '1')
			return (1);
		map->x++;
	}
	map->x = 0;
	map->y = 0;
	return (0);
}

int	map_itemcheck(t_solong *sl)
{
	while (sl->map->x < sl->map->height)
	{
		while (sl->map->map[sl->map->x][sl->map->y] != '\0')
		{
			if (sl->map->map[sl->map->x][sl->map->y] == 'P')
				sl->count->playerc += 1;
			if (sl->map->map[sl->map->x][sl->map->y] == 'C')
				sl->count->lootc += 1;
			if (sl->map->map[sl->map->x][sl->map->y] == 'E')
				sl->count->exitc += 1;
			sl->map->y++;
		}
		sl->map->y = 0;
		sl->map->x++;
	}
	if (sl->count->playerc != 1 || sl->count->lootc < 1
		|| sl->count->exitc != 1)
		return (1);
	sl->map->x = 0;
	sl->map->y = 0;
	return (0);
}

void	flood_fill(char **tab, int x, int y, t_map *map)
{
	if (x < 0 || x >= map->height || y < 0 || y >= map->width
		|| tab[x][y] == '1' || tab[x][y] == 'B')
		return ;
	tab[x][y] = 'B';
	flood_fill(tab, x + 1, y, map);
	flood_fill(tab, x - 1, y, map);
	flood_fill(tab, x, y + 1, map);
	flood_fill(tab, x, y - 1, map);
}

int	map_pathcheck(t_solong *sl)
{
	flood_fill(sl->map->mapcopy, sl->pos->px, sl->pos->py, sl->map);
	while (sl->map->x < sl->map->height)
	{
		while (sl->map->map[sl->map->x][sl->map->y] != '\0')
		{
			if (sl->map->map[sl->map->x][sl->map->y] == 'C'
				|| sl->map->map[sl->map->x][sl->map->y] == 'E')
			{
				if (sl->map->mapcopy[sl->map->x][sl->map->y] != 'B')
					return (1);
			}
			sl->map->y++;
		}
		sl->map->y = 0;
		sl->map->x++;
	}
	sl->map->x = 0;
	sl->map->y = 0;
	return (0);
}

// void	afunc(void)
// {
// 	int	x;
// 	int	y;

// 	... func((t_point){x, y})
// }

// void	func(t_point a)
// {
// 	a.x a.y
// }
