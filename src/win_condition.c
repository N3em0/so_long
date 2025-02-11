#include "so_long.h"

void    collect_loot(t_solong *sl)
{
    if (sl->map->map[sl->pos->cx][sl->pos->cy] == 'C' && sl->count->lootedc < sl->count->lootc)
    {
        sl->map->map[sl->pos->cx][sl->pos->cy] = '0';
        sl->count->lootedc += 1;
        printf("%d/%d collected\n", sl->count->lootedc, sl->count->lootc);
    }
    if (sl->count->lootedc == sl->count->lootc)
    {
        sl->map->map[sl->pos->ex][sl->pos->ey] = 'O';
        replace_exit(sl);
    }
}