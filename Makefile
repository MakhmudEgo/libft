# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 14:02:02 by mizola            #+#    #+#              #
#    Updated: 2020/05/03 18:46:52 by mizola           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
OSRC = *.o
FLAGS = -Wall -Wextra -Werror -c  -std=c99

all: $(NAME)
$(NAME):
	gcc $(FLAGS) $(SRC)
	ar rc $(NAME) $(OSRC)
	ranlib $(NAME)	

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
