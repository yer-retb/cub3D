OS = $(shell uname)

ifeq ($(OS), Linux)
	LIBS = minilibx-linux/libmlx.a Libft/libft.a -lXext -lX11 -lm
else
	LIBS = -lmlx -framework OpenGL -framework AppKit
endif

CC	=	gcc
CFLAGS = -Wall -Wextra -Werror


NAME = ./cub3D
SRC = rander/main.c rander/engine.c rander/player.c rander/raycast.c rander/draw_utils.c rander/getRays.c rander/utils.c rander/vector.c rander/projection.c rander/init_engine.c\
parcing/main_pars.c parcing/parce_map.c parcing/libft_beta.c parcing/print_error.c parcing/map_one.c parcing/map_one_utile.c parcing/map_one_utile_l.c parcing/map_one_utile_ll.c \
parcing/map_two.c parcing/handel_wall.c parcing/map_char_to_int.c parcing/get_next_line/get_next_line.c parcing/get_next_line/get_next_line_utils.c


O_FILES = $(SRC:.c=.o)

all:$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) $(LIBS) -o $(NAME)

linux: $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) $(LINUX_LIBS) -o $(NAME)

clean:
	rm -rf $(O_FILES) $(OBJS)

fclean:clean
	rm -rf $(NAME)

re : clean fclean all
