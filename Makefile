CC= arch -x86_64 gcc -Wall -Wextra -Werror
MLX= -L . -lmlx -framework OpenGL -framework Appkit
SRCS= main.c \
	  split_line.c \
	  utils.c \
	  map_valid.c \
	  map_square.c \
	  draw.c \
	  key.c \
	  check_valid.c

OBJS= $(SRCS:.c=.o)
NAME= so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(MLX) -o $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
