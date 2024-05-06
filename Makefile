NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = conversion.c ft_printf.c print.c utils.c

OBJS = $(SRCS:.c=.o)

AR = ar rcs

all: $(NAME)

$(NAME):: $(OBJS)
	${AR} ${NAME} ${OBJS}

%.o: %.c # this rule tells that in order to build any o file it should look for the corresponding c file
	$(CC) $(CFLAGS) -c $< -o $@ # the -I helps the compiler look for header files

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
