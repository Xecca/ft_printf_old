# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xecca <ensimgen@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 22:19:59 by Xecca             #+#    #+#              #
#    Updated: 2019/11/16 22:42:02 by Xecca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler in this project
# CC=gcc
# Flags in this project
# CFLAGS=-c -Wall -Werror -Wextra
# What does mean another flags:
# -o - флаг имени исполняемое файла (при компиляции объектных файшлов и статической библиотеки с разширением *.a (например, libft.a)).
# $@ - флаг, который подставляет значение первой переменной.
# $< - ?
# -c - флаг создаёт объектные файлы с расширением *.o

NAME=libftprintf.a

SOURCES=src/*.c

OBJECTS=*.o

INCLUDES=src/

# EXECUTABLE=ft_printf

all:$(NAME)

$(NAME):
	@make -C libft/ re
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SOURCES)
	ar -rc $(NAME) $(OBJECTS) libft/*.o
	ranlib $(NAME)

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

