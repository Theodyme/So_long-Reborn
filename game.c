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
	data->img->ptr = mlx_new_image(data->mlx->mlx_ptr, TILESIZE * data->map->x + TILESIZE * 2, TILESIZE * data->map->y + TILESIZE * 2);
	data->img->addr = mlx_get_data_addr(data->img->ptr, &(data->img->bpp),
			&(data->img->line_len), &(data->img->endian));
	data->img->width = TILESIZE * data->map->x + TILESIZE * 2;
    data->img->height = TILESIZE * data->map->y + TILESIZE * 2;
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
	int offset_y = ((floor.width / 2) / 2) + (floor.width / 25);

	int margin = TILESIZE * data->map->y / 2 - (TILESIZE / 2);
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	while (j < data->map->y)
	{
		x = margin - (j * offset_x);
		y = 0 + (j * offset_y);
		i = 0;
		while (i < data->map->x)
		{
			superpose_at(*data->img, floor, x, y);
			x += offset_x;
			y += offset_y;
			i++;
		}
		j++;
	}
}

void	draw_character(t_game_data *data)
{
	t_img chara;
    chara = open_xpm(CHARA, data);
    if (!chara.ptr)
	{	
		return;
	}
	t_img floor;
    floor = open_xpm(FLOOR, data);
    if (!floor.ptr)
	{	
		return;
	}

	int offset_x = floor.width / 2;
	int offset_y = ((floor.width / 2) / 2) + (floor.width / 25);

	int margin = TILESIZE * data->map->y / 2 - (TILESIZE / 2);

	int x = margin - (data->pposx * offset_x + (TILESIZE / 2));
	int y = 0 + (data->pposy * offset_y);
	superpose_at(*data->img, chara, x, y);
	return ;
}

void    init_window(t_game_data *data)
{
    data->mlx->mlx_ptr = mlx_init();
    data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, TILESIZE / 2 * (data->map->x + data->map->y), 62 / 2 * (data->map->x + data->map->y) + TILESIZE / 2, "Hello world!");\
    init_image(data);

    draw_iso_floor_only(data);
	draw_character(data);

    mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->img->ptr, 0, 0);
	mlx_loop(data->mlx->mlx_ptr);
    destroy_image(data);
    return ;
}

int    launch_game(t_game_data *data)
{
	printf("LAUNCH GAME = x is [%d]\n", data->map->x);
    init_structs(data);
    init_window(data);
    return EXIT_SUCCESS;
}