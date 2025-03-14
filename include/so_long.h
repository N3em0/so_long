/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:12:16 by egache            #+#    #+#             */
/*   Updated: 2025/03/14 14:30:28 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/include/ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void		*mlx;
	void		*win;
}				t_data;

typedef struct s_map
{
	int			x;
	int			y;
	int			width;
	int			height;
	char		**map;
	char		**mapcopy;
}				t_map;

typedef struct s_sprite
{
	void		*player;
	void		*wall;
	void		*empty;
	void		*loot;
	void		*oexit;
	void		*cexit;
}				t_sprite;

typedef struct s_count
{
	int			playerc;
	int			lootc;
	int			lootedc;
	int			exitc;
	int			stepc;
}				t_count;

typedef struct s_pos
{
	int			px;
	int			py;
	int			ex;
	int			ey;
}				t_pos;

typedef struct s_hud
{
	char		*lootedtmp;
	char		*loottmp;
	char		*lootcount;
	char		*hudloot;
	char		*stepcount;
	char		*hudstep;
}				t_hud;

typedef struct s_solong
{
	t_map		*map;
	t_data		*data;
	t_sprite	*sprite;
	t_count		*count;
	t_pos		*pos;
	t_hud		*hud;
}				t_solong;

int				main(int argc, char **argv);
void			valid_argument(int argc, char **argv, t_solong *sl);
void			struct_initialisation(t_solong *sl);
void			win_initialisation(t_solong *sl);

void			map_initialisation(char **argv, t_solong *sl);
int				map_getsize(char **argv, t_solong *sl);
void			map_get_playerpos(t_solong *sl, int x, int y);
void			map_get_exitpos(t_solong *sl, int x, int y);
int				map_alloc(t_solong *sl);
int				map_copy(char **argv, t_solong *sl, t_map *map);

int				map_wallcheck(t_map *map);
int				map_itemcheck(t_solong *sl);
int				map_charcheck(t_map *map);
void			flood_fill(char **tab, int x, int y, t_map *map);
int				map_pathcheck(t_solong *sl);

int				load_image(t_solong *sl);
void			put_image(t_solong *sl);
void			put_all_image(t_solong *sl);
void			replace_image(t_solong *sl, int oldy, int oldx);
void			replace_exit(t_solong *sl);

int				key_hook(int keycode, t_solong *sl);
void			move_up(t_solong *sl, t_map *map, t_pos *pos);
void			move_left(t_solong *sl, t_map *map, t_pos *pos);
void			move_right(t_solong *sl, t_map *map, t_pos *pos);
void			move_down(t_solong *sl, t_map *map, t_pos *pos);

void			collect_loot(t_solong *sl);
int				display_loot(t_solong *sl);
int				display_steps(t_solong *sl);
void			display_hud(t_solong *sl);

void			free_mlx(t_solong *sl);
int				free_destroy(t_solong *sl);
void			free_sl(t_solong *sl);
void			free_map(t_map *map);
void			free_hud(t_hud *hud);
void			free_exit(t_solong *sl, char *str, int ret);
#endif
