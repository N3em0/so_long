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
		free_exit(sl, "Window closed by escape\n", EXIT_SUCCESS);
	return (0);
}

void	move_up(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->px > 0 && map->map[pos->px - 1][pos->py] != '1')
	{
		pos->px--;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->py, pos->px, pos->py, pos->px + 1);
		if (map->map[pos->px][pos->py] == 'O')
			free_exit(sl, "Tia gagne fratelo\n", EXIT_SUCCESS);
	}
}
void	move_down(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->px < map->height && map->map[pos->px + 1][pos->py] != '1')
	{
		pos->px++;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->py, pos->px, pos->py, pos->px - 1);
		if (map->map[pos->px][pos->py] == 'O')
			free_exit(sl, "Tia gagne fratelo\n", EXIT_SUCCESS);
	}
}

void	move_left(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->py > 0 && map->map[pos->px][pos->py - 1] != '1')
	{
		pos->py--;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->py, pos->px, pos->py + 1, pos->px);
		if (map->map[pos->px][pos->py] == 'O')
			free_exit(sl, "Tia gagne fratelo\n", EXIT_SUCCESS);
	}
}

void	move_right(t_solong *sl, t_map *map, t_pos *pos)
{
	if (pos->py < map->width - 1 && map->map[pos->px][pos->py + 1] != '1')
	{
		pos->py++;
		sl->count->stepc++;
		display_hud(sl);
		replace_image(sl, pos->py, pos->px, pos->py - 1, pos->px);
		if (map->map[pos->px][pos->py] == 'O')
			free_exit(sl, "Tia gagne fratelo", EXIT_SUCCESS);
	}
}
