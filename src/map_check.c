#include "so_long.h"

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
			{
				sl->pos->cy = sl->map->y;
				sl->pos->cx = sl->map->x;
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
	return (sl->map->y = 0, sl->map->x = 0, 0);
}

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
	return (0);
}

void	flood_fill(char **tab, int x, int y, int height, int width, t_map *map)
{
	if (x < 0 || x >= map->height || y < 0 || y >= map->width
		|| tab[x][y] == '1' || tab[x][y] == 'B')
		return ;
	tab[x][y] = 'B';
	flood_fill(tab, x + 1, y, height, width, map);
	flood_fill(tab, x - 1, y, height, width, map);
	flood_fill(tab, x, y + 1, height, width, map);
	flood_fill(tab, x, y - 1, height, width, map);
}

int	map_pathcheck(t_solong *sl)
{
	flood_fill(sl->map->mapcopy, sl->pos->cx, sl->pos->cy, sl->map->height,
		sl->map->width, sl->map);

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
	return (sl->map->y = 0, sl->map->x = 0, 0);
}
