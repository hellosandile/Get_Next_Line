# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samkhize <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 10:44:16 by samkhize          #+#    #+#              #
#    Updated: 2019/07/04 13:06:36 by samkhize         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_g

FLAGS = -Wall -Werror -Wextra

LIB = ./libft

SRC = get_next_line.c main.c

OBJ = $(SRCS:.c=.o)

NAME: $(OBJ)
	$(FLAGS)

all: NAME

clean:
	rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: clean fclean $(NAME)
