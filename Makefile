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

BSRCS = checker.c		\
		rules.c				\
		input_check.c		\
		init_stacks.c		\
		counters.c			\
		calculations.c		\
		sort.c

all: $(NAME) bonus

bonus: $(BNAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(BNAME):
	$(CC) $(CFLAGS) $(BSRCS) -o $(BNAME)

clean:
	rm	-rf 

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BNAME)


re: fclean all

bre: fclean bonus

.PHONY: clean fclean re bre bonus all
