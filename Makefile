NAME = push_swap

BNAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c			\
		rules.c				\
		input_check.c		\
		init_stacks.c		\
		counters.c			\
		calculations.c		\
		sort.c

BSRCS = push_swap_bonus.c	\
	rules_bonus.c		\
	init_stacks.c		\
	input_check.c		\
	get_next_line.c		\
	get_next_line_utils.c

all: $(NAME)

bonus: $(BNAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(BNAME):
	$(CC) $(CFLAGS) $(BSRCS) -o $(BNAME)

clean:
	rm	-rf 

fclean: clean
	rm -rf $(NAME)

bfclean: 
	rm -rf $(BNAME)

re: fclean all

bre: bfclean bonus

.PHONY: clean fclean re
