/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:12:16 by egache            #+#    #+#             */
/*   Updated: 2025/02/06 20:58:15 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h" // modifier makefile pour enlever chemin !!!!!
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct s_sprite
{
	void		*chacha;
	void		*wall;
	void		*empty;
	void		*item;
	void		*oexit;
	void		*cexit;
}				t_sprite;

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

typedef struct s_solong
{
	t_map		*map;
	t_data		*data;
	t_sprite	*sprite;

}				t_solong;

int				ciao(t_solong *sl);
int				key_hook(int keycode, t_solong *sl);
int				map_getsize(char **argv, t_solong *sl);
int				map_alloc(t_solong *sl);
int				map_copy(char **argv, t_solong *sl);
int				map_image(t_solong *sl);
int				map_check(t_solong *sl);
int				main(int argc, char **argv);
void			free_map(t_solong *sl);
#endif
