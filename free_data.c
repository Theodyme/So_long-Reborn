#include "lib.h"

void    free_map_data(t_map **map_data)
{
    (*map_data)->y--;
    while ((*map_data)->y >= 0)
    {
        free((*map_data)->map[(*map_data)->y]);
        (*map_data)->y--;
    }
    free((*map_data)->map);
    free(*map_data);
    *map_data = NULL;
    return ;
}