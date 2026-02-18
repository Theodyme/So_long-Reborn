#ifndef LIB_H
# define LIB_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#include <stdio.h>

// INCLUDE PRINTF HERE
// INCLUDE GNL HERE
#include "gnl/get_next_line.h"

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

#endif