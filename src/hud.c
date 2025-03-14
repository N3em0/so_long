/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:36 by teatime           #+#    #+#             */
/*   Updated: 2025/03/14 13:36:44 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_loot(t_solong *sl)
{
	sl->hud->lootedtmp = ft_itoa(sl->count->lootedc);
	sl->hud->loottmp = ft_itoa(sl->count->lootc);
	sl->hud->lootcount = ft_strjoin(" / ", sl->hud->loottmp);
	sl->hud->hudloot = ft_strjoin(sl->hud->lootedtmp, sl->hud->lootcount);
	if (!sl->hud->lootedtmp || !sl->hud->loottmp || !sl->hud->lootcount
		|| !sl->hud->hudloot)
		return (1);
	mlx_string_put(sl->data->mlx, sl->data->win, 25, 70, 0xffffff,
		sl->hud->hudloot);
	return (0);
}

int	display_steps(t_solong *sl)
{
	sl->hud->stepcount = ft_itoa(sl->count->stepc);
	sl->hud->hudstep = ft_strjoin(sl->hud->stepcount, " steps");
	if (!sl->hud->stepcount || !sl->hud->hudstep)
		return (1);
	mlx_string_put(sl->data->mlx, sl->data->win, 25, 40, 0xffffff,
		sl->hud->hudstep);
	return (0);
}

void	display_hud(t_solong *sl)
{
	mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->wall, 0,
		0);
	if (display_steps(sl) == 1 || display_loot(sl) == 1)
	{
		free_hud(sl->hud);
		free_exit(sl, "Error\nMalloc failed\n", EXIT_FAILURE);
	}
	else
		free_hud(sl->hud);
	ft_printf("%d / %d collected and ", sl->count->lootedc, sl->count->lootc);
	ft_printf("%d steps\n", sl->count->stepc);
}

void	free_hud(t_hud *hud)
{
	if (hud && hud->lootedtmp != NULL)
		free(hud->lootedtmp);
	if (hud && hud->loottmp != NULL)
		free(hud->loottmp);
	if (hud && hud->lootcount != NULL)
		free(hud->lootcount);
	if (hud && hud->hudloot != NULL)
		free(hud->hudloot);
	if (hud && hud->stepcount != NULL)
		free(hud->stepcount);
	if (hud && hud->hudstep != NULL)
		free(hud->hudstep);
}
