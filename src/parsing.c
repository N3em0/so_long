#include "so_long.h"

int    map_copy(char **argv, t_map *map)
{
    int fd;
    char *str;
    int len;
    int i;
    fd = open(argv[1], O_RDONLY);
    // map->x = 0;
    // map->y = 0;
    i = 0;
    if (fd < 0)
        return 1;
    while ((str = get_next_line(fd)))
    {
        printf("getting lenght\n");
        len = ft_strlen(str);
        if (map->width == 0)
            map->width = len;
        // if (map->width != 0 && (map->width > len || map->width < len))
        // {
        //     printf("c'est la ?");
        //     return (1);
        // }
        map->height++;
        free(str);
    }
    close(fd);
    map->map = (char **)malloc(map->height *sizeof(char *));
    printf("first malloc\n");
    if (!map->map)
        return (1);
    while(i < map->height)
    {
        map->map[i] = malloc(map->width * sizeof(char));
        printf("second malloc\n");
        if (!map->map[i])
            return (1);
        i++;
    }
    fd = open(argv[1], O_RDONLY);
    while ((str = get_next_line(fd)))
    {
        while (str[map->y] != '\0' && str[map->y] != '\n')
        {
            map->map[map->x][map->y] =  str[map->y];
            map->y++;
        }
        printf("%s", map->map[map->x]);
        printf("\n");
        free(str);
        map->y = 0;
        map->x++;
    }
    close(fd);
    printf("apres le close ?");
    return (0);
}

int map_image(t_map *map, t_data *data)
{
    map->x = 0;
    map->y = 0;

    while (map->x < map->height)
    {
        while (map->y < map->width)
        {
            if (map->map[map->x][map->y] == '1')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->wall, map->y * 120, map->x * 120);
            } 
            if (map->map[map->x][map->y] == '0')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->empty, map->y * 120, map->x * 120);
            }
            if (map->map[map->x][map->y] == 'C')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->item, map->y * 120, map->x * 120);        
            }
            if (map->map[map->x][map->y] == 'E')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->oexit, map->y * 120, map->x * 120);
            }
            if (map->map[map->x][map->y] == 'P')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->chacha, map->y * 120, map->x * 120);
            }
            map->y++;
        }
        map->y = 0;
        map->x++;
    }
    return (0);
}
