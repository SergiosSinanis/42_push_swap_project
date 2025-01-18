/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:55:09 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/06 15:48:44 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct t_stack_a
{
	int					data;
	struct t_stack_a	*next;
}						t_stack_a;

typedef struct t_stack_b
{
	int					data;
	struct t_stack_b	*next;
}						t_stack_b;

typedef struct t_stacks
{
	struct t_stack_a	*top_a;
	struct t_stack_b	*top_b;
	struct t_ranges		*ranges;
	struct t_actions	*actions;
	struct t_easy		*easy;
}						t_stacks;

typedef struct t_ranges
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_ranges;

typedef struct t_actions
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_actions;

typedef struct t_easy
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_easy;

char		**ft_parse_input(int argc, char *argv[], int *arg_count);
void		ft_is_input_only_ints(int arg_count, char *argv[]);
void		ft_is_input_in_int_limits(int argc, char *argv[]);
void		ft_check_double_numbers_in_stack(t_stack_a *top_a);
void		ft_print_error(void);
t_stack_a	*ft_lstlast_a(t_stack_a *top_a);
t_stack_b	*ft_create_stack_b(int argc, char *argv[]);
t_stack_a	*ft_create_stack_a(int count, char **args);
t_stack_b	*ft_new_node_b(int data);
t_stack_a	*ft_create_stack_a(int argc, char *argv[]);
t_stack_a	*ft_new_node_a(int data);
void		ft_check_empty_arg(char *arg);
void		ft_is_valid_number(char *arg);
void		ft_delete_all_nodes_a(t_stack_a **lst);
void		ft_delete_all_nodes_b(t_stack_b **lst);
void		ft_sort_stacks(t_stacks *stacks);
void		ft_sort_two(t_stacks *stacks);
void		ft_swap(t_stacks *stacks, char c);
void		ft_swap_a(t_stack_a *top_a, int print_flag);
void		ft_swap_b(t_stack_b *top_b, int print_flag);
void		ft_rotate(t_stacks *stacks, char c);
void		ft_rotate_a(t_stacks *stacks, t_stack_a *top_a, int print_flag);
void		ft_rotate_b(t_stacks *stacks, t_stack_b *top_b, int print_flag);
void		ft_rev_rotate(t_stacks *stacks, char c);
void		ft_rev_rotate_a(t_stacks *stacks, t_stack_a *top_a, int print_flag);
void		ft_rev_rotate_b(t_stacks *stacks, t_stack_b *top_b, int print_flag);
void		ft_sort_three(t_stacks *stacks, int terminate_flag);
void		ft_three_sort(t_stacks *stacks, int nb1, int nb2, int nb3);
void		ft_sort_four(t_stacks *stacks);
void		ft_free_structure(t_stacks *stacks);
int			ft_is_stack_sorted(t_stacks *stacks);
int			ft_lstsize_b(t_stack_b *top);
int			ft_lstsize_a(t_stack_a *top);
void		ft_push(t_stacks *stacks, char c);
void		ft_push_to_pop_a(t_stacks *stacks);
void		ft_push_to_pop_b(t_stacks *stacks);
void		ft_last_push_to_a(t_stacks *stacks);
void		ft_push_to_empty_b(t_stacks *stacks);
void		ft_max_min_a(t_stacks *stacks);
void		ft_max_a(t_stacks *stacks, t_stack_a *top_a);
void		ft_min_a(t_stacks *stacks, t_stack_a *top_a);
void		ft_max_min_b(t_stacks *stacks);
void		ft_min_b(t_stacks *stacks, t_stack_b *top_b);
void		ft_max_b(t_stacks *stacks, t_stack_b *top_b);
void		ft_move_all_back_to_a(t_stacks *stacks);
void		ft_order(t_stacks *stacks);
void		ft_perform_rotations(t_stacks *stacks);
int			ft_find_index_stack_a(t_stacks *stacks, int nbr);
int			ft_find_index_stack_b(t_stacks *stacks, int nbr);
void		ft_fewer_actions(t_stacks *stacks);
void		ft_perform_best_moves(t_stacks *stacks);
void		ft_check_moves(t_stacks *stacks);
void		ft_check_cost(t_stacks *stacks, int i);
void		ft_check_double_moves(t_stacks *stacks);
void		ft_get_top_stack_a(t_stacks *stacks, t_stack_a *top_a, int i);
void		ft_new_max_or_min_stack_b(t_stacks *stacks);
void		ft_new_nb_in_stack_b(t_stacks *stacks, int nb);
int			ft_search_nb_in_stack_b(t_stacks *stacks, int nbr);
void		ft_put_new_max_a(t_stacks *stacks);
void		ft_perform_moves_max_a(t_stacks *stacks);
void		ft_put_new_min_a(t_stacks *stacks);
void		ft_perform_moves_min_a(t_stacks *stacks);
void		ft_put_new_number_in_a(t_stacks *stacks, t_stack_b *top_b);
void		ft_perform_moves_number_stack_a(t_stacks *stacks);
int			ft_search_a(t_stacks *stacks, int nbr);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);
void		ft_putchar_l(char c, int *length);
void		ft_specifier(char c, va_list *my_args, int *length);
int			ft_printf(const char *specifier, ...);
void		ft_putstr2(char *str, int *length);
void		ft_putnbr(int nbr, int *length);
void		ft_putunsigned(unsigned int u, int *length);
void		ft_putpointer(size_t pointer, int *length);
void		ft_16print(unsigned int nb, int *length, char x_or_X);
void		ft_putstr_fd(char *s, int fd);
void		ft_free_split(char **split);
char		**ft_split(char const *s, char c);
char		**ft_parse_input_split(char *arg, int *arg_count);

#endif
