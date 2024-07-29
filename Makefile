NAME= push_swap
FILES= cost.c groups.c index.c sort_size.c target.c push_swap.c main.c
FILES_BIS= comm_push.c comm_rotate.c comm_rr.c comm_swap.c lst_utils.c lst_utils2.c parse.c sort.c  
INCLUDE= push_swap.h
OBJS= $(FILES:.c=.o)
OBJS_BIS= $(FILES_BIS:.c=.o)

NAME_BONUS= checker
FILES_BONUS= checker.c
OBJS_BONUS= $(FILES_BONUS:.c=.o)

CC= cc
FLAGS= -Wall -Wextra -Werror -g3

LIBFT = ./libft/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(OBJS) $(OBJS_BIS) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(OBJS_BIS) $(LIBFT)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS) $(INCLUDE)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_BIS) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS) $(OBJS_BIS)
	rm -f $(OBJS_BONUS) $(OBJS_BIS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C libft fclean

re: fclean all

.PHONY : all bonus clean fclean re
