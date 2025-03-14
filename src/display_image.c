/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:25 by teatime           #+#    #+#             */
/*   Updated: 2025/03/14 14:31:11 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_image(t_solong *sl)
{
	int	img_width;
	int	img_height;

	sl->sprite->player = mlx_xpm_file_to_image(sl->data->mlx, "img/char.xpm",
			&img_width, &img_height);
	sl->sprite->wall = mlx_xpm_file_to_image(sl->data->mlx, "img/wall.xpm",
			&img_width, &img_height);
	sl->sprite->empty = mlx_xpm_file_to_image(sl->data->mlx, "img/empty.xpm",
			&img_width, &img_height);
	sl->sprite->loot = mlx_xpm_file_to_image(sl->data->mlx, "img/c.xpm",
			&img_width, &img_height);
	sl->sprite->cexit = mlx_xpm_file_to_image(sl->data->mlx, "img/cexit.xpm",
			&img_width, &img_height);
	sl->sprite->oexit = mlx_xpm_file_to_image(sl->data->mlx, "img/oexit.xpm",
			&img_width, &img_height);
	if (!sl->sprite->player || !sl->sprite->wall || !sl->sprite->loot
		|| !sl->sprite->cexit || !sl->sprite->oexit || !sl->sprite->empty)
		return (1);
	return (0);
}

void	put_image(t_solong *sl)
{
	if (sl->map->map[sl->map->x][sl->map->y] == '1')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->wall,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == '0')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->empty,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == 'C')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->loot,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == 'E')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->cexit,
			sl->map->y * 120, sl->map->x * 120);
	}
	if (sl->map->map[sl->map->x][sl->map->y] == 'P')
	{
		mlx_put_image_to_window(sl->data->mlx, sl->data->win,
			sl->sprite->player, sl->map->y * 120, sl->map->x * 120);
	}
}

void	put_all_image(t_solong *sl)
{
	while (sl->map->x < sl->map->height)
	{
		while (sl->map->y < sl->map->width)
		{
			put_image(sl);
			sl->map->y++;
		}
		sl->map->y = 0;
		sl->map->x++;
	}
}

void	replace_image(t_solong *sl, int oldy, int oldx)
{
	mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->player,
		sl->pos->py * 120, sl->pos->px * 120);
	mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->empty,
		oldy * 120, oldx * 120);
}

void	replace_exit(t_solong *sl)
{
	mlx_put_image_to_window(sl->data->mlx, sl->data->win, sl->sprite->oexit,
		sl->pos->ey * 120, sl->pos->ex * 120);
}

// enum
// {
// 	R,
// 	L,
// 	U,
// 	D
// }
// int dir
// x, y, U
// if (dir == U) x+1
