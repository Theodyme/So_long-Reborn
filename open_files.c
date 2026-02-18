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

int count_map_height(char *filename, t_map **map_data)
{
    int fd;
    char *line;

    (*map_data)->y = 0;
    line = NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf(BLUE "[log]: " DEFAULT);
        printf("unable to open file. ");
        printf(BLACK "[COUNTING HEIGHT]\n" DEFAULT);
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
        (*map_data)->y++;
    }
    close(fd);
    printf(BLUE "[log]: " DEFAULT);
    printf("found [%d] lines for the height of the map. ", (*map_data)->y);
    printf(BLACK "[COUNTING HEIGHT]\n" DEFAULT);
    return (EXIT_SUCCESS);
}

int open_map(char *filename, t_map **map_data)
{
    int fd;
    char *line;

    line = NULL;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf(BLUE "[log]: " DEFAULT);
        printf("unable to open file. ");
        printf(BLACK "[OPEN MAP]\n" DEFAULT);
        return (EXIT_FAILURE);
    }
    
    int i = 0;

    line = get_next_line(fd);
    while (line != NULL)
    {
        printf(BLUE "[log]: " DEFAULT);
        printf("opened line [%s] ... ", trim_newline(line));
        printf(BLACK "[OPEN MAP]\n" DEFAULT);
        (*map_data)->map[i++] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (EXIT_SUCCESS);
}