NAME= push_swap
FILES= comm_push.c comm_rotate.c comm_rr.c comm_swap.c \
		lst_utils.c lst_utils2.c sort.c sort_size.c groups.c \
		parse.c cost.c target.c push_swap.c main.c print.c opti.c index.c
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
