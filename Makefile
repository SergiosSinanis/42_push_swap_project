NAME = push_swap

SRCS = ./srcs/fewer_actions.c ./srcs/ft_parse_input.c ./srcs/get_top.c ./srcs/max_min_a.c ./srcs/max_min_b.c ./srcs/push.c ./srcs/push_swap.c ./srcs/return_to_a.c ./srcs/rev_rotate.c ./srcs/rotate.c ./srcs/sorting_alg.c ./srcs/sort_two_three_four.c ./srcs/stack_a_list.c ./srcs/stack_b_list.c ./srcs/swap.c ./srcs/utils.c ./srcs/utils2.c ./srcs/ft_atoi.c ./srcs/ft_utils.c ./srcs/ft_printf.c ./srcs/ft_split.c

INCLUDES = ./includes

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_bonus: fclean
