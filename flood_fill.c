#include "lib.h"

char **map_cpy(t_map **map_data)
{
    char **mcpy;
    int i;

    i = 0;
    mcpy = malloc(sizeof(char *) * ((*map_data)->y + 1));
    if (!mcpy)
        return NULL;
    while ((*map_data)->map[i]) {
        mcpy[i] = ft_strdup((*map_data)->map[i]);
        i++;
    }
    mcpy[i] = NULL;
    return mcpy;
}

int flood_fill_call(t_map **map_data, t_game_data **game_data)
{
    char **mcpy;
    int items;
    int i;

    items = 0;
    mcpy = map_cpy(map_data);

    flood_fill(mcpy, (*game_data)->pposy, (*game_data)->pposx, game_data, &items);
    printf(BLACK);
    i = 0;
    print_log(NULL, NULL);
    printf("missing %d exit and %d items.\n", (*game_data)->exit, ((*game_data)->items - items));
    while (mcpy[i])
    {
        free(mcpy[i]);
        i++;
    }
    free(mcpy);
    if ((*game_data)->exit == 1 || ((*game_data)->items - items))
    {
        (print_err("map is invalid and not doable!\n", NULL));
        return EXIT_FAILURE;
    }
    print_success("map is valid and doable!\n", NULL);
    return EXIT_SUCCESS;
}

int    is_oce(char c, int *items, t_game_data **game_data)
{
    if (c == 'E')
    {
        (*game_data)->exit -= 1;
        return 1;
    }
    else if (c == 'C')
    {
        (*items)++;
        return 1;
    }
    else if (c == '0')
        return 1;
    else
        return 0;
}

int flood_fill(char **map, int posy, int posx, t_game_data **game_data, int *items)
{
    if (map[posy][posx - 1] && is_oce(map[posy][posx - 1], items, game_data))
    {
        map[posy][posx - 1] = 'F';
        flood_fill(map, posy, posx - 1, game_data, items);
    }
    if (map[posy][posx + 1] && is_oce(map[posy][posx + 1], items, game_data))
    {
        map[posy][posx + 1] = 'F';
        flood_fill(map, posy, posx + 1, game_data, items);
    }
    if (map[posy - 1][posx] && is_oce(map[posy - 1][posx], items, game_data))
    {
        map[posy - 1][posx] = 'F';
        flood_fill(map, posy - 1, posx, game_data, items);
    }
    if (map[posy + 1][posx] && is_oce(map[posy + 1][posx], items, game_data))
    {
        map[posy + 1][posx] = 'F';
        flood_fill(map, posy + 1, posx, game_data, items);
    }
    return 1;
}