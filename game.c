#include "lib.h"

int init_assets(t_game_data *data)
{
    data->assets = malloc(sizeof(t_assets));
    if (!data->assets)
        return (EXIT_FAILURE);

    data->assets->floor = malloc(sizeof(t_data));
    if (!data->assets->floor)
        return (EXIT_FAILURE);

    return (EXIT_SUCCESS);
}

void    load_assets(t_game_data *data)
{
    int tilesize = TILESIZE;
    data->assets->floor->img = mlx_xpm_file_to_image(data->mlx, FLOOR, &tilesize, &tilesize);
    return ;
}

void    line_building(char *row, t_game_data *data, int y)
{
    int x;

    x = 0;
    while (row[x])
    {
        if(row[x] == '0')
            mlx_put_image_to_window(data->mlx, data->win, data->assets->floor->img,
                    (x * TILESIZE / 2), (y * TILESIZE / 2));
        x++;
    }
}

void    lvl_building(t_game_data *data)
{
    int y;

    y = 0;
    while (data->map->map[y])
    {
        line_building(data->map->map[y], data, y);
        y++;
    }
    return ;
}

void    init_window(t_game_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 900, 600, "Hello world!");
    init_assets(data);
    load_assets(data);
    lvl_building(data);
    // mlx_put_image_to_window(data->mlx, data->win, data->assets->floor->img, TILESIZE, TILESIZE);
	mlx_loop(data->mlx);
    return ;
}

int    launch_game(t_game_data *data)
{
    init_window(data);
    return EXIT_SUCCESS;
}