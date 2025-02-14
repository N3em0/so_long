/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:58 by teatime           #+#    #+#             */
/*   Updated: 2025/02/14 17:34:01 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
