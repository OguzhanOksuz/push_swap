M_NAME = push_swap

B_NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#-------MANDATORY----------

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

#-------BONUS----------

B_SRCS = bonus.c		\
	 input_join.c		\
	 ft_split.c		\
	 input_check.c		\
	 init_stacks.c		\
	 rules.c

B_OBJS = $(B_SRCS:.c=.o)

#----------------------

mandatory: $(M_NAME)

bonus: $(B_NAME)

all: mandatory bonus

$(M_NAME): $(M_OBJS)
	$(CC) $(CLFAGS) $(M_OBJS) -o $(M_NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)

clean:
	rm -rf $(M_OBJS)
	rm -rf $(B_OBJS)

fclean: clean
	rm -rf $(M_NAME)
	rm -rf $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus mandatory
