#include "lib.h"

/*		open xpm: ouvre une image xpm et stocke dans un t_img toutes les donnees necessaires (height, width, endian, addr, ...)
		bpp = bits par pixel (souvent 32)
		line_len = nombre d’octets par ligne
		endian = ordre des octets
		addr = pointeur vers le buffer mémoire de l’image
*/

t_img       open_xpm(char * path, t_game_data *data)
{
	t_img   image;

	image.ptr = mlx_xpm_file_to_image(data->mlx->mlx_ptr, path, &image.width, &image.height);
	if (!image.ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

/*		put_pixel: ecrit un pixel a la position (x, y) SI la couleur n'est pas transparente (none, 0xFF000000) */

void    	put_pixel(t_img idata, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (!(x < 0) && !(y < 0) && (x < idata.width) && (y < idata.height))
	{
		dst = idata.addr + (y * idata.line_len + x * (idata.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

/*		get_pixel: recupere un pixel a la position (x, y) */

unsigned int	get_pixel(t_img idata, int x, int y)
{
	unsigned int color;

	color = *(unsigned int *)((idata.addr + (y * idata.line_len) + (x * idata.bpp / 8)));
	return (color);
}

/*		superpose_at: dessine l'image src sur l'image dst a la position (x, y) */

void			superpose_at(t_img dst, t_img src, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < src.width) {
		j = 0;
		while (j < src.height) {
			put_pixel(dst, x + i, y + j, get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}