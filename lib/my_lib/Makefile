##
## EPITECH PROJECT, 2019
## lib_for_tetris
## File description:
## Makefile
##

SRC =	$(shell find ./src -name *.c)


OBJ	=	$(SRC:.c=.o)

NAME 	=	mylib.a

CPPFLAGS = -I ../../include -lm -g
all: 	$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" || echo -e "\e[91;5m[KO]\e[25m" $< "\033[5m\n    T'est même pas cappable de compiler sans error t'est une merde ${USER}"

$(NAME):	$(OBJ)
	@ar rc -o $(NAME) $(OBJ)
	@mkdir -p ../../include

clean:
	@echo -e "\e[1m\e[32m\n******************************** NETTOYAGE de tous les objet ************************************\033[0m"
	@rm -f $(OBJ)
	@echo -e "\e[1m\e[32m******************************** FIN du nettoyages ************************************\n\033[0m"

re: fclean all

fclean:	clean
	@rm -f $(NAME)
.PHONY:	clean
