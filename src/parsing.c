#include "so_long.h"

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
    char **map;
}           t_map;

void    map_loading(int argc, char **argv, t_data *win, t_map *map)
{
    int fd;
    char *str;
    int i;

    fd = open(argv[1], O_RDONLY);
    map->x = 0;
    map->y = 0;
    if (fd < 0)
        return ;
    while (fd > 0)
    {
        str = (get_next_line(fd));
        while (str[i] != '\0' && str[i] != '\n')
        {
            if (str[i] == '1')
            {
                map->map[map->y][map->x] =  
            } 
            else if (str[i] == '0')
            {}
            else if (str[i] == 'C')
            {}
            else if (str[i] == 'E')
            {}
            else if (str[i] == 'P')
            {}
            map->y++;
            i++;
        }
        //map->x++;
    }
}