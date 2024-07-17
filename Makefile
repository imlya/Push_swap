NAME= push_swap
FILES= lst_utils.c lst_utils2.c main.c parse.c print.c push.c reverse_rotate.c \
		rotate.c sort.c sort_utils.c initial.c swap.c push_swap.c cost.c
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