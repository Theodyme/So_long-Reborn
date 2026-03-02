#include "lib.h"

int init_structs(t_game_data *data)
{
    data->mlx = malloc(sizeof(t_mlx_data));
    if (!data->mlx)
        return (EXIT_FAILURE);

    data->img = malloc(sizeof(t_img));
    if (!data->img)
        return (EXIT_FAILURE);

    return (EXIT_SUCCESS);
}

int     init_image(t_game_data *data)
{
	data->img->ptr = mlx_new_image(data->mlx->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->ptr, &(data->img->bpp),
			&(data->img->line_len), &(data->img->endian));
	data->img->width = WIDTH;
    data->img->height = HEIGHT;
	return EXIT_SUCCESS;
}

void	destroy_image(t_game_data *data) {
	if (data->img->ptr && data->mlx->mlx_ptr) 
       mlx_destroy_image(data->mlx->mlx_ptr, data->img->ptr);
    return ;
}

void draw_iso_floor_only(t_game_data *data)
{
    t_img floor;
    floor = open_xpm(FLOOR, data);
    if (!floor.ptr)
        return;

    int offset_x = floor.width / 2;
	int offset_y = (floor.width / 2) / 2;

	superpose_at(*data->img, floor, 0, 0);
	superpose_at(*data->img, floor, 0 + offset_x + 1, 0 + offset_y + 1);
	int x = 0;
	int y = 0;
	int i = 0;
	printf("x is [%d]\n", data->map->x);
	while (i <= data->map->x)
	{
		superpose_at(*data->img, floor, x, y);
		x += offset_x;
		y += offset_y;
		i++;
	}

    // while (data->map->map[y])
    // {
    //     x = 0;
    //     while (data->map->map[x])
    //     {
    //         int iso_x = (x) + offset_x;
    //         int iso_y = (y) + offset_y;

    //         superpose_at(*data->img, floor, iso_x, iso_y);
    //         x++;
    //     }
    //     y++;
    // }
}

void    init_window(t_game_data *data)
{
    data->mlx->mlx_ptr = mlx_init();
    data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, 900, 600, "Hello world!");\
    init_image(data);

    draw_iso_floor_only(data);

    mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->img->ptr, 0, 0);
	mlx_loop(data->mlx->mlx_ptr);
    destroy_image(data);
    return ;
}

int    launch_game(t_game_data *data)
{
    init_structs(data);
    init_window(data);
    return EXIT_SUCCESS;
}