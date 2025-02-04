/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teatime <teatime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:12:16 by egache            #+#    #+#             */
/*   Updated: 2025/02/04 18:09:29 by teatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h" // modifier makefile pour enlever chemin !!!!!
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_data
{
	void	*chacha;
    void    *wall;
    void    *empty;
    void    *item;
    void    *oexit;
    void    *cexit;
	void	*mlx;
	void	*win;
}			t_data;

typedef struct s_map
{
    int x;
    int y;
    int width;
    int height;
    char **map;
}           t_map;

int	ciao(t_data *data);
int	key_hook(int keycode, t_data *data);
int map_copy(char **argv, t_map *map);
int map_image(t_map *map, t_data *data);
int main(int argc, char **argv);

#endif
