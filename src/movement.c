#include "so_long.h"

int	key_hook(int keycode, t_solong *sl)
{
	if (keycode == 119)
	{
		move_up(sl, sl->map, sl->pos);
		collect_loot(sl);
	}
	if (keycode == 115)
	{
		move_down(sl, sl->map, sl->pos);
		collect_loot(sl);
	}
	if (keycode == 97)
	{
		move_left(sl, sl->map, sl->pos);
		collect_loot(sl);
	}
	if (keycode == 100)
	{
		move_right(sl, sl->map, sl->pos);
		collect_loot(sl);
	}
	else if (keycode == 65307)
		free_exit("window closed", sl, 1);
	return (0);
}

void	move_up(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->cx > 0 && map->map[pos->cx - 1][pos->cy] != '1')
	{
		pos->cx--;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->cy, pos->cx, pos->cy, pos->cx + 1);
		if (map->map[pos->cx][pos->cy] == 'O')
			free_exit("Tia gagne fratelo", sl, 0);
	}
}
void	move_down(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->cx < map->height && map->map[pos->cx + 1][pos->cy] != '1')
	{
		pos->cx++;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->cy, pos->cx, pos->cy, pos->cx - 1);
		if (map->map[pos->cx][pos->cy] == 'O')
			free_exit("Tia gagne fratelo\n", sl, 0);
	}
}

void	move_left(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->cy > 0 && map->map[pos->cx][pos->cy - 1] != '1')
	{
		pos->cy--;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->cy, pos->cx, pos->cy + 1, pos->cx);
		if (map->map[pos->cx][pos->cy] == 'O')
			free_exit("Tia gagne fratelo\n", sl, 0);
	}
}

void	move_right(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->cy < map->width - 1 && map->map[pos->cx][pos->cy + 1] != '1')
	{
		pos->cy++;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->cy, pos->cx, pos->cy - 1, pos->cx);
		if (map->map[pos->cx][pos->cy] == 'O')
			free_exit("Tia gagne fratelo\n", sl, 0);
	}
}
