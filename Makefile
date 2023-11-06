NAME		=	libft.a

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRCS		=	atoi.c \
				mem_edit.c \
				mem_test.c \
				string_edit.c \
				string_test.c \
				char_format.c \
				char_test.c \
				main.c \

SRCS_FOLDER	=	srcs
$(SRCS)		=	$(addprefix $(SRCS_FOLDER)/,$(SRCS))

OBJS_FOLDER	=	objects
OBJS		=	$(addprefix $(OBJS_FOLDER)/,$(SRCS:.c=.o))

INCLUDES		=	includes

all: $(NAME)

$(NAME): $(OBJS)
	ar crs ${NAME} ${OBJS}
	@echo "$(NAME) has been successfully created."

$(OBJS_FOLDER)/%.o: $(SRCS_FOLDER)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c -o $@ $<

clean:
	@rm -rf $(OBJS_FOLDER)
	@echo "object files and directories have been removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) and object files have been removed."

re: fclean all
