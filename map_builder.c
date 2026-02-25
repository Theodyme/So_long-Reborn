#include "lib.h"

char    *trim_newline(char *str)
{
    int i;

    if (!str)
        return NULL;
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            return str;
        }
        i++;
    }
    return str;        
}

int count_map_height(char *filename, t_map *map_data)
{
    int fd;
    char *line;

    map_data->y = 0;
    line = NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_err("unable to open file.", "COUNTING HEIGHT");
        return (EXIT_FAILURE);
    }
    
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf(BLUE "[log]: " DEFAULT);
        printf("opened line [%s] ... ", trim_newline(line));
        printf(BLACK "[COUNTING HEIGHT]\n" DEFAULT);
        free(line);
        line = get_next_line(fd);
        map_data->y++;
    }
    close(fd);
    printf(BLUE "[log]: " DEFAULT);
    printf("found [%d] lines for the height of the map. ", map_data->y);
    printf(BLACK "[COUNTING HEIGHT]\n" DEFAULT);
    return (EXIT_SUCCESS);
}

int open_map(char *filename, t_map *map_data)
{
    int fd;
    char *line;

    line = NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_err("unable to open file.", "OPEN MAP");
        return (EXIT_FAILURE);
    }
    
    int i = 0;

    line = get_next_line(fd);
    while (line != NULL)
    {
        printf(BLUE "[log]: " DEFAULT);
        printf("opened line [%s] ... ", trim_newline(line));
        printf(BLACK "[OPEN MAP]\n" DEFAULT);
        map_data->map[i++] = ft_strdup(trim_newline(line));
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    map_data->map[i] = NULL;
    close(fd);
    return (EXIT_SUCCESS);
}