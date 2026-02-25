# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# VARIABLES

SRCS	=	main.c \
			data_builder.c \
			map_builder.c \
			free_data.c \
			flood_fill.c \
			game.c \
			utils_lib/ft_strdup.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c
LIB		=	mlx/libmlx_Linux.a
OBJ		=	${SRCS:.c=.o}
NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# **************************************************************************** #
# RULES

%.o:	%.c
	@${CC} ${CFLAGS} -c -g $< -o $@
	@echo "$(BLUE)Compiling $<...$(END_COLOR)"

$(NAME):	${OBJ} Makefile
# 	@make --no-print-directory -C ft_printf
	@make --no-print-directory -C mlx
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) -lXext -lX11
	@make clean
	@echo "$(GREEN)Compiled $(NAME) :)$(END_COLOR)"

all:	${NAME}

clean:
	@rm -f ${OBJ}
	@echo "$(YELLOW)Removed object files.$(END_COLOR)"

fclean: clean
	@make fclean --no-print-directory -C ft_printf
	@make clean --no-print-directory -C mlx
	@rm -f ${NAME}
	@echo "$(YELLOW)Cleaned libraries and $(NAME) executable.$(END_COLOR)"

re:		fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME) and $(LIB)!$(END_COLOR)"

.PHONY:	all clean fclean re