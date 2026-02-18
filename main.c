#include "lib.h"

void    init_map_data(char *filename, t_map **map_data)
{
   *map_data = malloc(sizeof(t_map));
    if (!*map_data)
        return ;
    count_map_height(filename, map_data);
    printf("%d\n", (*map_data)->y);
    (*map_data)->map = malloc(sizeof(char *) * (*map_data)->y);
    (*map_data)->x = 0;
    printf(BLUE "[log]: " DEFAULT);
    printf("initiated map data.\n");
    return ;
}

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

int     main(int ac, char **av)
{
    char    *filename;
    t_map   *map_data;

    if (ac != 2)
    {
        printf("error: program requires at least and only the map as argument\n");
        return EXIT_FAILURE;
    }

    filename = ft_strdup(av[1]);
    printf(BLUE "[log]: " DEFAULT);
    printf("opening map file [%s] ...\n", filename);

    init_map_data(filename, &map_data);
    if (!map_data)
        return EXIT_FAILURE;
    if (open_map(filename, &map_data) == EXIT_FAILURE)
    {
        printf(RED "[log]: " DEFAULT);
        printf("failure opening [%s]. aborting.\n", filename);
    }
    free(filename);
    free_map_data(&map_data);
    return EXIT_SUCCESS;
}