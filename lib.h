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
# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"

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
	int			player;
	int			exit;
	int			items;
	int			pposx;
	int			pposy;
	// t_assets	assets;
}				t_game_data;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
int		ft_is_in_charset(char *str, char *charset);

void	print_err(char *str, char *call);
void	print_log(char *str, char *call);
void	print_success(char *str, char *call);

char	*trim_newline(char *str);

int		init_map_data(char *filename, t_map **map_data);
int		init_game_data(t_game_data **game_data);
int		data_builder(t_map **map_data, t_game_data **game_data);

void	free_map_data(t_map **map_data);

int		count_map_height(char *filename, t_map **map_data);
int		open_map(char *filename, t_map **map_data);

char	**map_cpy(t_map **map_data);
int		flood_fill_call(t_map **map_data, t_game_data **game_data);
int		is_oce(char c, int *items, t_game_data **game_data);
int		flood_fill(char **map, int posy, int posx, t_game_data **game_data, int *items);

#endif