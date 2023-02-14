NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c			\
		push_swap_utils.c	\
		rules.c				\
		input_check.c		\
		init_stacks.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm	-rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
