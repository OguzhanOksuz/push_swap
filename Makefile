NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c			\
		rules.c				\
		input_check.c		\
		init_stacks.c		\
		counters.c			\
		calculations.c		\
		sort.c				

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm	-rf 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
