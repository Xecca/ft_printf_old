# Compiler in this project
# CC=gcc
# Flags in this project
# CFLAGS=-c -Wall -Werror -Wextra
# What does mean another flags:
# -o - флаг имени исполняемое файла (при компиляции объектных файшлов и статической библиотеки с разширением *.a (например, libft.a)).
# $@ - флаг, который подставляет значение первой переменной.
# $< - ?
# -c - флаг создаёт объектные файлы с расширением *.o
SOURCES=src/*.c

OBJECTS=*.o

INCLUDES=src/

NAME=libftprintf.a
# EXE=ft_printf
all: $(NAME)

$(NAME):
	# @make -C libft/ re
	# $(CC) $(SOURCES) $(CFLAGS)
	# $(CC) $(OBJECTS) $(INCLUDES)$(NAME) -o $(EXE)
	# rm -rf $(OBJECTS)
	@make -C libft/ re
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SOURCES)
	ar -rc $(NAME) $(OBJECTS) libft/*.o
	ranlib $(NAME)
	# rm -rf $(INCLUDES)$(OBJECTS)
	# rm -rf libft/$(OBJECTS)

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME) $(INCLUDES)$(NAME) $(EXE)
	@make -C libft/ fclean

re: fclean all
