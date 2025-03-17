NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c init.c check_fonk.c draw.c manjul.c utils.c calculate.c 
OBJ = $(SRC:.c=.o)

LIBMLX = -L./minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)  

fclean: clean
	rm -f $(NAME) 

re: fclean all  
