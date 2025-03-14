/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:58 by teatime           #+#    #+#             */
/*   Updated: 2025/03/14 16:38:36 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_loot(t_solong *sl)
{
	if (sl->map->map[sl->pos->px][sl->pos->py] == 'C'
		&& sl->count->lootedc < sl->count->lootc)
	{
		sl->map->map[sl->pos->px][sl->pos->py] = 'P';
		sl->count->lootedc += 1;
		display_hud(sl);
	}
	if (sl->count->lootedc == sl->count->lootc)
	{
		sl->map->map[sl->pos->ex][sl->pos->ey] = 'O';
		replace_exit(sl);
	}
}
