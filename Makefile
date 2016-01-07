# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 18:24:47 by jleu              #+#    #+#              #
#    Updated: 2016/01/07 18:48:05 by jleu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fillit.c					\
	  ft_backtrack.c			\
	  ft_comptetri.c			\
	  ft_generate_square.c		\
	  ft_get_sqrsize.c			\
	  ft_getpieces.c			\
	  ft_removepiece.c			\
	  ft_resetpiece.c			\
	  ft_setpiece.c				\
	  ft_test_fichier_valid.c	\

FLAGS = -Wall					\
		-Wextra					\
		-Werror					\

NAME = fillit

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ):
	gcc $(FLAGS) -c $(SRC)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) libft.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
