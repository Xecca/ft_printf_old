# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 16:29:37 by aponomar          #+#    #+#              #
#    Updated: 2019/11/17 11:29:55 by Xecca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library.
NAME=libft.a

# Source functions.
SRCS 		:= *.c

# Source object files.
OBJECTS		:= o.o

# Files directory.
INCLUDES 	:= ./

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
