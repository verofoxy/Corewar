##
## EPITECH PROJECT, 2019
## day10
## File description:
## task01
##

SRC = lib/my/my_putchar.c \
		lib/my/my_put_nbr.c \
		lib/my/my_putstr.c \
		lib/my/my_printf_s.c   \
		lib/my/my_strcpy.c  \
		lib/my/my_strlen.c  \
		my_printf.c \
		lib.c       \
		my_printf_type.c    \
		my_printf_convert.c
OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all: 	$(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< && echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" || echo -e "\e[91;5m[KO]\e[25m" $< "\033[5m\n    T'est même pas cappable de compiler sans error t'est une merde ${USER}"

############create lybrairies ###################
$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

############clean files tmp and *.o##############
clean:		$(OBJ)
	@rm -f $(OBJ)

############clean *.o and $(NAME)################
fclean:	clean
	@rm -f $(NAME)
	@find . -name "*[#|~]" -delete  -o -name "[#]*" -delete


re: all clean

auteur:
	echo $(USER) > auteur
