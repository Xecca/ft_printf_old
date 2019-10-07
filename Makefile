#Compiler in this project
CC=gcc
# Flags in this project
CFLAGS=-c -Wall -Werror -Wextra
# What does mean another flags:
# -o - флаг имени исполняемое файла (при компиляции объектных файшлов и статической библиотеки с разширением *.a (например, libft.a)).
# $@ - флаг, который подставляет значение первой переменной.
# $< - ?
# -c - флаг создаёт объектные файлы с расширением *.o
SOURCES=src/*.c

OBJECTS=*.o

INCLUDES=libft/libft.a

EXECUTABLE=ft_printf

all: $(EXECUTABLE)

$(EXECUTABLE):
	@make -C libft/ re
	$(CC) $(SOURCES) $(CFLAGS)
	$(CC) $(OBJECTS) $(INCLUDES) -o $@
	rm -rf $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

fclean: clean
	/bin/rm -f $(EXECUTABLE)
	@make -C libft/ fclean

re: fclean all
