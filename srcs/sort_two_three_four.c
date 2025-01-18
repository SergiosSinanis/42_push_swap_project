/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:36:06 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/06 18:32:34 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stacks *stacks)
{
	ft_swap(stacks, 'a');
	ft_delete_all_nodes_a(&stacks->top_a);
	exit (0);
}

void	ft_sort_three(t_stacks *stacks, int terminate_flag)
{
	t_stack_a	*top_a;
	int			nb1;
	int			nb2;
	int			nb3;

	top_a = stacks->top_a;
	nb1 = top_a->data;
	nb2 = top_a->next->data;
	nb3 = top_a->next->next->data;
	ft_three_sort(stacks, nb1, nb2, nb3);
	if (terminate_flag)
	{
		ft_delete_all_nodes_a(&stacks->top_a);
		exit (0);
	}
}

void	ft_three_sort(t_stacks *stacks, int nb1, int nb2, int nb3)
{
	if (nb1 > nb2 && nb1 < nb3 && nb2 < nb3)
		ft_swap(stacks, 'a');
	else if (nb1 > nb2 && nb1 > nb3 && nb2 < nb3)
		ft_rotate(stacks, 'a');
	else if (nb1 < nb2 && nb1 > nb3 && nb2 > nb3)
		ft_rev_rotate(stacks, 'a');
	else if (nb1 > nb2 && nb1 > nb3 && nb2 > nb3)
	{
		ft_swap(stacks, 'a');
		ft_rev_rotate(stacks, 'a');
	}
	else if (nb1 < nb2 && nb1 < nb3 && nb2 > nb3)
	{
		ft_swap(stacks, 'a');
		ft_rotate(stacks, 'a');
	}
}

void	ft_sort_four(t_stacks *stacks)
{
	t_actions	*my_actions;
	t_easy		*my_easy;
	t_ranges	*my_ranges;

	my_actions = ft_calloc(1, sizeof(t_actions));
	stacks->actions = my_actions;
	my_easy = ft_calloc(1, sizeof(t_easy));
	stacks->easy = my_easy;
	my_ranges = ft_calloc(1, sizeof(t_ranges));
	stacks->ranges = my_ranges;
	ft_push(stacks, 'b');
	ft_sort_three(stacks, 0);
	ft_move_all_back_to_a(stacks);
	ft_free_structure(stacks);
	exit (0);
}
