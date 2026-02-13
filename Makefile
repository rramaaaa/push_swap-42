NAME = push_swap
SRC = bench.c check_dup.c disorder.c find.c list.c operation.c operation_one.c operation_two.c/
parse.c parse_helper.c put_ops.c put_ops_2.c put_ops_3.c rank.c stack.c/
adaptive_strategy.c complex_strategy.c medium_strategy_helper.c medium_strategy.c simple_strategy.c print_bench.c error_handler.c main.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re