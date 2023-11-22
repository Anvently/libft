NAME		=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRCS			=	ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
				ft_strlcat.c ft_strlcpy.c ft_strchr.c \
				ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
				ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_striteri.c ft_uitoa.c ft_ultoa.c ft_ultoa_base.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstinsert.c

INCLUDES	=	./

OBJS_FOLDER	=	./
OBJS		=	$(addprefix $(OBJS_FOLDER)/,$(SRCS:.c=.o))

.PHONY		=	all clean fclean test re bonus so

all: $(NAME)

test: a.out
	./a.out

a.out: main.c $(NAME)
	@$(CC) $(CFLAGS) -I$(INCLUDES) main.c ${NAME}
	@echo "Executable has been successfully created."

$(NAME): $(OBJS)
	@ar crs ${NAME} ${OBJS}
	@echo "$(NAME) has been successfully created."


%.o: %.c Makefile libft.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c -o $@ $<

so: libft.so

libft.so: $(SRCS)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(INCLUDES) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
	cp libft.so ../libft-unit-tests/libft.so

clean:
	@rm -rf $(OBJS) libft.so
	@echo "object files have been removed."

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@echo "$(NAME) and object files have been removed."

re: fclean all
