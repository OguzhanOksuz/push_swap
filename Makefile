NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c			\
		push_swap_utils.c	\
		rules.c				\
		input_check.c		\
		init_stacks.c

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm	-rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
