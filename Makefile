NAME		=	libft.a

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRC			=	ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
				ft_strlcat.c ft_strlcpy.c ft_strchr.c \
				ft_strrchr.c ft_strnstr.c ft_strncmp.c \
				ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_FOLDER	=	srcs
SRCS		=	$(addprefix $(SRCS_FOLDER)/,$(SRC))

SRC_BONUS	=	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c
SRCS_BONUS		=	$(addprefix $(SRCS_FOLDER)/,$(SRC_BONUS))

INCLUDES	=	includes/

OBJS_FOLDER	=	objects
OBJS		=	$(addprefix $(OBJS_FOLDER)/,$(SRC:.c=.o))
OBJS_BONUS	=	$(addprefix $(OBJS_FOLDER)/,$(SRC_BONUS:.c=.o))

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

bonus: $(OBJS) $(OBJS_BONUS)
	@ar crs ${NAME} ${OBJS} $(OBJS_BONUS)
	@echo "$(NAME) with bonus has been successfully created."

$(OBJS_FOLDER)/%.o: $(SRCS_FOLDER)/%.c Makefile includes/libft.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c -o $@ $<

so: objects/libft.so

objects/libft.so: $(SRCS)
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(INCLUDES) $(SRCS)
	gcc -nostartfiles -shared -o objects/libft.so $(OBJS)
	cp objects/libft.so ../libft-unit-tests/libft.so

clean:
	@rm -rf $(OBJS_FOLDER)
	@echo "object files and directories have been removed."

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@echo "$(NAME) and object files have been removed."

re: fclean all
