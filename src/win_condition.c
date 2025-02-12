#include "so_long.h"

void	collect_loot(t_solong *sl)
{
	if (sl->map->map[sl->pos->cx][sl->pos->cy] == 'C'
		&& sl->count->lootedc < sl->count->lootc)
	{
		sl->map->map[sl->pos->cx][sl->pos->cy] = '0';
		sl->count->lootedc += 1;
		display_hud(sl);
	}
	if (sl->count->lootedc == sl->count->lootc)
	{
		sl->map->map[sl->pos->ex][sl->pos->ey] = 'O';
		replace_exit(sl);
	}
}
void	display_loot(t_solong *sl)
{
	char	*hudloot;
	char	*loot;
	char	*loottmp;
	char	*lootedtmp;

	lootedtmp = ft_itoa(sl->count->lootedc);
	loottmp = ft_itoa(sl->count->lootc);
	loot = ft_strjoin(" / ", loottmp);
	hudloot = ft_strjoin(lootedtmp, loot);
	printf("%d/%d collected\n", sl->count->lootedc, sl->count->lootc);
	mlx_string_put(sl->data->mlx, sl->data->win, 25, 70, 0xffffff, hudloot);
	free(loottmp);
	free(lootedtmp);
	free(hudloot);
	free(loot);
}
void	display_steps(t_solong *sl)
{
	char	*stepcount;
	char	*hudsteps;

	printf("%d steps\n", sl->count->stepc);
	stepcount = ft_itoa(sl->count->stepc);
	hudsteps = ft_strjoin(stepcount, " steps");
	mlx_string_put(sl->data->mlx, sl->data->win, 25, 40, 0xffffff, hudsteps);
	free(stepcount);
	free(hudsteps);
}
void	display_hud(t_solong *sl)
{
	mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->wall, 0,
		0);
	display_steps(sl);
	display_loot(sl);
}
