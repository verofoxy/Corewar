##
## EPITECH PROJECT, 2019
## my_runner
## File description:
## my_rpg
##

USER := $(shell whoami)

SRC =	$(shell find ./src -name *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	asm


CFLAGS	:= -Wall -Wextra -g

DEBUG_FLAGS = -g3 -ggdb

ifeq ($(DEBUGS), yes)
	$(CFLAGS)	+= $(DEBUG_FLAGS)
endif

CPPFLAGS +=	-I ../include/

LIBS += ../lib/my_lib/mylib.a ../lib/my_printf/libmy.a ../lib/linked_list/linked_list.a

all:	$(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" || echo -e "\e[91;5m[KO]\e[25m" $< "\033[5m\n    T'est même pas cappable de compiler sans error t'est une merde ${USER}"

$(NAME):	$(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

re: fclean all

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

debug:	$(OBJ)
	@echo "compilation de débug en en cour"
	@$(CC)  -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
	@echo "compilation terminer"

create:
	@mkdir -p src
	@mkdir -p include
	@mkdir -p lib
	@mkdir -p tests
	@clear

.PHONY:	fclean clean all re create debug
