##
## EPITECH PROJECT, 2020
## My Library - HashMap
## File description:
## Make
##

.PHONY: all re clean fclean

SRC = src/hashmap_get.c\
	src/my_hashmap_contains.c\
	src/my_hashmap_convert.c\
	src/my_hashmap_count.c\
	src/my_hashmap_set.c\
	src/my_hashmap_clear.c\
	src/my_hashmap_convert_keys.c

NAME = libmy_hashmap.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

CPPFLAGS = -I./

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	#cp $(NAME) ../
	#mkdir -p ../../include
	#cp my_hashmap.h ../../include

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run:
	$(CC) $(CFLAGS) $(CPPFLAGS) -lcriterion -o unit_tests --coverage $(SRC) tests/test_simple_test.c
	./unit_tests