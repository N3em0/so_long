/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:31 by teatime           #+#    #+#             */
/*   Updated: 2025/02/21 13:18:43 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx(t_solong *sl)
{
	if (sl->sprite->player)
		mlx_destroy_image(sl->data->mlx, sl->sprite->player);
	if (sl->sprite->wall)
		mlx_destroy_image(sl->data->mlx, sl->sprite->wall);
	if (sl->sprite->empty)
		mlx_destroy_image(sl->data->mlx, sl->sprite->empty);
	if (sl->sprite->cexit)
		mlx_destroy_image(sl->data->mlx, sl->sprite->cexit);
	if (sl->sprite->oexit)
		mlx_destroy_image(sl->data->mlx, sl->sprite->oexit);
	if (sl->sprite->loot)
		mlx_destroy_image(sl->data->mlx, sl->sprite->loot);
	if (sl->data->win && sl->data->mlx)
		mlx_destroy_window(sl->data->mlx, sl->data->win);
	if (sl->data->mlx)
	{
		mlx_destroy_display(sl->data->mlx);
		free(sl->data->mlx);
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->map)
	{
		while (i < map->height)
			free(map->map[i++]);
		free(map->map);
	}
	i = 0;
	if (map && map->mapcopy)
	{
		while (i < map->height)
			free(map->mapcopy[i++]);
		free(map->mapcopy);
	}
}

void	free_sl(t_solong *sl)
{
	if (sl->sprite)
		free(sl->sprite);
	if (sl->count)
		free(sl->count);
	if (sl->data)
		free(sl->data);
	if (sl->pos)
		free(sl->pos);
	if (sl->map)
		free(sl->map);
	if (sl->hud)
		free(sl->hud);
	free(sl);
}
int	free_destroy(t_solong *sl)
{
	free_exit(sl, "Window close by X\n", EXIT_SUCCESS);
	return (0);
}
void	free_exit(t_solong *sl, char *str, int ret)
{
	if (sl)
	{
		free_mlx(sl);
		free_map(sl->map);
		free_sl(sl);
	}
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(ret);
}
