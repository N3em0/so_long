/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:12:16 by egache            #+#    #+#             */
/*   Updated: 2025/02/07 21:50:31 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
}				t_map;

typedef struct s_sprite
{
	void		*chacha;
	void		*wall;
	void		*empty;
	void		*loot;
	void		*oexit;
	void		*cexit;
}				t_sprite;

typedef struct s_count
{
	int			chachac;
	int			lootc;
	int			exitc;
}				t_count;

typedef struct s_cpos
{
	int			cx;
	int			cy;
}				t_cpos;

typedef struct s_solong
{
	t_map		*map;
	t_data		*data;
	t_sprite	*sprite;
	t_count		*count;
	t_cpos		*cpos;

}				t_solong;

void			struct_initialisation(t_solong *sl);
void			map_initialisation(char **argv, t_solong *sl);
int				map_getsize(char **argv, t_solong *sl);
int				map_alloc(t_solong *sl);
int				map_copy(char **argv, t_solong *sl);
int				map_loadimage(t_solong *sl);
int				map_put_all_image(t_solong *sl);
void			map_put_image(t_solong *sl);
int				map_wallcheck(t_solong *sl);
int				map_itemcheck(t_solong *sl);
int				key_hook(int keycode, t_solong *sl);
int				ciao(t_solong *sl);
void			free_sl(t_solong *sl);
void			free_map(t_map *map);
void			free_exit(char *str, t_solong *sl, int ret);
int				main(int argc, char **argv);
#endif
