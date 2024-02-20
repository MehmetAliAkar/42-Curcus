SRCS= ft_printf.c ft_printuint.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re