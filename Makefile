
NAME = libftprintf.a

SRCS =	ft_hex.c\
		ft_putnbr.c\
		ft_putptr.c\
		ft_printfutils.c\
		ft_printf.c\

OBJECTS = ${SRCS:.c=.o}
COMPILER = gcc
CFLAGS = -Wall -Werror -Wextra
LIBRARY_NAME = libftprintf.a

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJECTS}
	ar rcs ${LIBRARY_NAME} ${OBJECTS}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${LIBRARY_NAME}

re: fclean all
