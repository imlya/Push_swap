# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imatek <imatek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 15:38:38 by imatek            #+#    #+#              #
#    Updated: 2024/07/05 16:28:03 by imatek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pushswap.a
FILES= push.c rotate.c swap.c reverse_rotate.c lst_utils.c parse.c mainc.c
CC= cc
FLAGS= -Wall -Wextra -Werror
INCLUDE= push_swap.h
OBJS= $(FILES:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I INCLUDE -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re