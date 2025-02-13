#include "so_long.h"

void	collect_loot(t_solong *sl)
{
	if (sl->map->map[sl->pos->px][sl->pos->py] == 'C'
		&& sl->count->lootedc < sl->count->lootc)
	{
		sl->map->map[sl->pos->px][sl->pos->py] = '0';
		sl->count->lootedc += 1;
		display_hud(sl);
	}
	if (sl->count->lootedc == sl->count->lootc)
	{
		sl->map->map[sl->pos->ex][sl->pos->ey] = 'O';
		replace_exit(sl);
	}
}
