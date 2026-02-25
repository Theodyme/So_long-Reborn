#include "lib.h"

// int init_assets(t_game_data *data)
// {
//     data->assets = malloc(sizeof(t_assets));
//     if (!data->assets)
//         return (EXIT_FAILURE);

//     data->assets->floor = malloc(sizeof(t_data));
//     if (!data->assets->floor)
//         return (EXIT_FAILURE);

//     return (EXIT_SUCCESS);
// }

// void    load_assets(t_game_data *data)
// {
//     // int tilesize = TILESIZE;
//     // data->assets->floor->img = mlx_xpm_file_to_image(data->mlx, FLOOR, &tilesize, &tilesize);
//     return ;
// }

t_img	new_file_img(char * path, t_game_data *data) {
	t_img image;

	image.ptr = mlx_xpm_file_to_image(data->mlx->mlx_ptr, path, &image.width, &image.height);
	if (!image.ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

void	put_pixel_img(t_img idata, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < idata.width && y < idata.height) {
		dst = idata.addr + (y * idata.line_len + x * (idata.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_img idata, int x, int y) {
	return (*(unsigned int *)((idata.addr
			+ (y * idata.line_len) + (x * idata.bpp / 8))));
}

void	put_img_to_img(t_img dst, t_img src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src.width) {
		j = 0;
		while (j < src.height) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}


// void    line_building(char *row, t_game_data *data, int y)
// {
//     int x;

//     x = 0;
//     while (row[x])
//     {
//         if(row[x] == '0')
//         {

//         }
//         x++;
//     }
// }

// void    lvl_building(t_game_data *data)
// {
//     int y;

//     y = 0;
//     while (data->map->map[y])
//     {
//         line_building(data->map->map[y], data, y);
//         y++;
//     }
//     return ;
// }


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
    int offset_x = (data->img->width / 2) - (data->map->x / 2) * TILESIZE;
    int offset_y = 0; // marge top
    float iso_ratio = 1.2;

    int y = 0;
    int x = 0;

    t_img floor;
    floor = new_file_img(FLOOR, data);
    if (!floor.ptr)
        return;

    while (data->map->map[y])
    {
        x = 0;
        while (data->map->map[x])
        {
            int iso_x = (x - y) * (TILESIZE / iso_ratio) + offset_x;
            int iso_y = (x + y) * (TILESIZE / 2) + offset_y;

            put_img_to_img(*data->img, floor, iso_x, iso_y);
            x++;
        }
        y++;
    }
}

void    init_window(t_game_data *data)
{
    data->mlx->mlx_ptr = mlx_init();
    data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, 900, 600, "Hello world!");
    // init_assets(data);
    // load_assets(data);
    init_image(data);

    // lvl_building(data);
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