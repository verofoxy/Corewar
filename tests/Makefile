##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Unit tests makefile
##

NAME	=	unit_tests

CPPFLAGS +=	-I ../include/

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-g3		\
		--coverage

LIBS += ../lib/my_lib/mylib.a ../lib/my_printf/libmy.a ../lib/linked_list/linked_list.a

all: $(NAME)

$(NAME):	$(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
