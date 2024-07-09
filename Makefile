NAME= push_swap
FILES= push.c rotate.c swap.c reverse_rotate.c lst_utils.c parse.c main.c print.c utils.c
CC= cc
FLAGS= -Wall -Wextra -Werror
INCLUDE= push_swap.h
OBJS= $(FILES:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME) 

$(NAME): $(LIBFT) $(OBJS) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY : all clean fclean re