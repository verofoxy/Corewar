##
## EPITECH PROJECT, 2019
## my_runner
## File description:
## my_rpg
##

CFLAGS	:= -Wall -Wextra -Werror -g

CPPFLAGS = -I include/

DEBUG_FLAGS = -g3 -ggdb -g

ifeq ($(DEBUGS), yes)
	$(CFLAGS)	+= $(DEBUG_FLAGS)
endif

UT_NAME = unit_tests

UT_SRC	= $(shell find ./asm/src/parser -name *.c)
UT_SRC	+= $(shell find ./asm/src/traducteur -name *.c)
UT_SRC	+= $(shell find ./asm/src/lexer -name *.c)
UT_SRC	+= $(shell find ./asm/src/errno -name *.c)

UT_OBJ	=	$(UT_SRC:.c=.o)			\
			$(shell find ./tests/src -name *.c)

LIBS += lib/my_lib/mylib.a lib/my_printf/libmy.a lib/linked_list/linked_list.a

all:	$(NAME)
	@make -C asm/
	@make -C corewar/

$(NAME):	load_lib
	@echo -e "\e[1m\e[32m\n******************* compilation du programe $(NAME) *******************************\033[0m"
	@make -C asm/
	@make -C corewar/
	@echo -e "\e[1m\e[32m******************* fin de compilation du programe $(NAME) *******************************\n\033[0m"

load_lib:
	@echo -e "\e[1m\e[32m******************* compilation de la lib mylib *******************************\033[0m"
	@make re -C lib/my_lib
	@make clean -C lib/my_lib
	@echo -e "\e[1m\e[32m ******************************** FIN DE COMPILATION de la lib *********************\033[0m"
	@echo -e "\e[1m\e[32m******************* compilation de la lib linked_list *******************************\033[0m"
	@make re -C lib/linked_list
	@make clean -C lib/linked_list
	@echo -e "\e[1m\e[32m ******************************** FIN DE COMPILATION de la lib *********************\033[0m"
	@echo -e "\e[1m\e[32m******************* compilation de la lib my_printf *******************************\033[0m"
	@make re -C lib/my_printf/
	@make clean -C lib/my_printf
	@echo -e "\e[1m\e[32m *****************  FIN DE COMPILATION de la my_printf *********************\033[0m"

re: fclean
	@make load_lib
	@echo -e "\e[1m\e[32m******************* compilation du programe $(NAME) *******************************\033[0m"
	@make re -C asm/
	@make re -C corewar/
	@echo -e "\e[1m\e[32m******************* fin de compilation du programe $(NAME) *******************************\033[0m"

clean:
	@make clean -C asm/
	@make clean -C corewar/

fclean: clean
	@make fclean -C lib/my_printf
	@make fclean -C lib/my_lib
	make fclean -C lib/linked_list
	make fclean -C corewar/
	make fclean -C asm/

tests_run: load_lib $(UT_OBJ)
		gcc --coverage -g3 $(CFLAGS) -o $(UT_NAME) $(UT_OBJ) $(LIBS) -lcriterion
		./unit_tests


debug:	$(OBJ)
	@echo -e "\e[1m\e[32m\n******************* compilation de la lib mylib *******************************\033[0m"
	@make -C lib/my_lib
	@make clean -C lib/my_lib
	@echo -e "\e[1m\e[32m ******************************** FIN DE COMPILATION de la lib *********************\n\033[0m"

	@echo -e "\e[1m\e[32m\n******************* compilation de la lib my_printf *******************************\033[0m"
	@make -C lib/printf/
	@echo -e "\e[1m\e[32m *****************  FIN DE COMPILATION de la my_printf *********************\n\033[0m"

	@make load_lib
	@echo "compilation de débug en en cour"
	@$(CC)  -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
	@echo "compilation terminer"

create:
	@mkdir -p src
	@mkdir -p include
	@mkdir -p lib
	@mkdir -p tests
	@clear

.PHONY:	fclean clean all re debug create
