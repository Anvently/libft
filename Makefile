CC=cc
INCLUDES=includes/
FLAGS=-Wall -Wextra -Werror -I$(INCLUDES)
SRCS=srcs/*.c
OBJS=${SRCS:.c=.o}
NAME=libft.a

all:${NAME}

${NAME}: ${OBJS}
	ar crs ${NAME} ${OBJS}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

%.o:%c
	${CC} ${FLAGS} srcs/*.c -o $@

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f libft.a

re: fclean all
