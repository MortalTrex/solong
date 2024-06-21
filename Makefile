NAME = so_long

SRC = src/check.c \
	  src/free_error.c \
	  src/main.c \
	  src/player.c \
	  src/map.c \

GNL_FILES = get_next_line.c\
		get_next_line_utils.c

GNLS = $(addprefix lib/gnl/,${GNL_FILES})

FLAGS = -Wall -Werror -Wextra -I includes/ -g

LIB = libft/libft.a ft_printf/libftprintf.a mlx/libmlx.a

DEPS = $(addprefix lib/,${LIB:%.c=%.o})

all: ${NAME}

${NAME} : ${SRC}
	make -C lib/mlx
	make -C lib/libft
	make -C lib/ft_printf
	cc ${FLAGS} ${SRC} -L lib/mlx -l mlx -I mlx -lXext -lX11 -lm -lz -o ${NAME} ${DEPS} ${GNLS}

clean:
	make -C lib/mlx clean
	make -C lib/libft clean
	make -C lib/ft_printf clean

fclean: clean
	rm -rf ${NAME}

re:    fclean all

.PHONY: all clean fclean re
