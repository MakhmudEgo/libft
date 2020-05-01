# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 14:02:02 by mizola            #+#    #+#              #
#    Updated: 2020/05/01 19:14:13 by mizola           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
ICS = /
OSRC = *.o

all:
	gcc -c $(SRC)
	ar rc $(NAME) $(OSRC)
	ranlib $(NAME)	

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
