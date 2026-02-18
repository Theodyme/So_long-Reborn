#ifndef LIB_H
# define LIB_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>

// INCLUDE PRINTF HERE
// INCLUDE GNL HERE
# include "gnl/get_next_line.h"

# define DEFAULT "\033[0m"
# define RED "\033[91m"
# define BLUE "\033[94m"
# define BLACK "\e[0;90m"

# define TILESIZE 20
# define CHARA "textures/character.xpm"
# define WALL "textures/wall.xpm"
# define FLOOR "textures/floor.xpm"
# define ITEM "textures/item.xpm"
# define EXIT "textures/exit.xpm"
# define START "textures/start.xpm"
# define BACKGROUND "textures/background.xpm"

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
}				t_map;

typedef struct s_assets
{

}				t_assets;

typedef struct s_game_data
{
	int			items;
	t_assets	assets;
}				t_game_data;

char    *trim_newline(char *str);
int 	count_map_height(char *filename, t_map **map_data);
int 	open_map(char *filename, t_map **map_data);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
int		ft_is_in_charset(char *str, char *charset);

#endif