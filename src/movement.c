#include "so_long.h"

int	key_hook(int keycode, t_solong *sl)
{
	if (keycode == 119)
    {
        move_up(sl);
        collect_loot(sl); 
    }
	if (keycode == 115)
	{
        move_down(sl);
        collect_loot(sl);
	}
	if (keycode == 97) //left
	{
        move_left(sl);
        collect_loot(sl);
	}
	if (keycode == 100) // right
	{
        move_right(sl);
        collect_loot(sl);
    }
    else if (keycode == 65307)
        free_exit("window closed", sl, 1);
    return (0);
}
    
void    move_up(t_solong *sl)
{
    if (sl->pos->cx > 0 && sl->map->map[sl->pos->cx - 1][sl->pos->cy] != '1' && sl->map->map[sl->pos->cx - 1][sl->pos->cy] != 'E')
    {
        sl->pos->cx--;
        printf("%d steps\n", sl->count->stepc++);
        replace_image(sl, sl->pos->cy, sl->pos->cx, sl->pos->cy, sl->pos->cx + 1);
        if (sl->map->map[sl->pos->cx - 1][sl->pos->cy] == 'O')
            free_exit("Tia gagne fratelo", sl, 0);  
    }
}
void    move_down(t_solong *sl)
{
    if (sl->pos->cx < sl->map->height && sl->map->map[sl->pos->cx + 1][sl->pos->cy] != '1' && sl->map->map[sl->pos->cx + 1][sl->pos->cy] != 'E')
    {
        sl->pos->cx++;
        printf("%d steps\n", sl->count->stepc++);
        replace_image(sl, sl->pos->cy, sl->pos->cx, sl->pos->cy, sl->pos->cx - 1);
        if (sl->map->map[sl->pos->cx + 1][sl->pos->cy] == 'O')
            free_exit("Tia gagne fratelo\n", sl, 0);
    }
}

void    move_left(t_solong *sl)
{
    if (sl->pos->cy > 0 && sl->map->map[sl->pos->cx][sl->pos->cy - 1] != '1' && sl->map->map[sl->pos->cx][sl->pos->cy - 1] != 'E')
    {
        sl->pos->cy--;
        printf("%d steps\n", sl->count->stepc++);
        replace_image(sl, sl->pos->cy, sl->pos->cx, sl->pos->cy + 1, sl->pos->cx);
        if (sl->map->map[sl->pos->cx][sl->pos->cy] == 'O')
            free_exit("Tia gagne fratelo\n", sl, 0);
    }
}

void    move_right(t_solong *sl)
{
    if (sl->pos->cy < sl->map->width - 1 && sl->map->map[sl->pos->cx][sl->pos->cy + 1] != '1' && sl->map->map[sl->pos->cx][sl->pos->cy + 1] != 'E')
    {
        sl->pos->cy++;
        printf("%d steps\n", sl->count->stepc++);
        replace_image(sl, sl->pos->cy, sl->pos->cx, sl->pos->cy - 1, sl->pos->cx);
        if (sl->map->map[sl->pos->cx][sl->pos->cy + 1] == 'O')
            free_exit("Tia gagne fratelo\n", sl, 0);
    }
}
