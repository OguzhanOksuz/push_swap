M_NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

M_SRCS = push_swap.c	\
	 input_join.c	\
	 ft_split.c	\
	 input_check.c	\
	 init_stacks.c	\
	 rules.c	\
	 counters.c	\
	 calculations.c	\
	 sort_big.c	\
	 sort_engine.c

M_OBJS = $(M_SRCS:.c=.o)

all: $(M_NAME)

$(M_NAME): $(M_OBJS)
	$(CC) $(CLFAGS) $(M_OBJS) -o $ $(M_NAME)

clean:
	rm -rf $(M_OBJS)

fclean: clean
	rm -rf $(M_NAME)

re: fclean all

.PHONY: all clean fclean re
