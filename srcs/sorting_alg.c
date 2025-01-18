/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:08:10 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/06 17:55:53 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stacks(t_stacks *stacks)
{
	if (ft_is_stack_sorted(stacks))
		return ;
	if (ft_lstsize_a(stacks->top_a) == 2)
	{
		ft_sort_two(stacks);
	}
	else if (ft_lstsize_a(stacks->top_a) == 3)
	{
		ft_sort_three(stacks, 1);
	}
	else if (ft_lstsize_a(stacks->top_a) == 4)
	{
		ft_sort_four(stacks);
	}
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	ft_fewer_actions(stacks);
	ft_sort_three(stacks, 0);
	ft_move_all_back_to_a(stacks);
}

int	ft_is_stack_sorted(t_stacks *stacks)
{
	t_stack_a	*top_a;
	int			nb;
	int			i;

	i = 0;
	top_a = stacks->top_a;
	nb = top_a->data;
	while (i < ft_lstsize_a(stacks->top_a) - 1)
	{
		top_a = top_a->next;
		if (nb > top_a->data)
			return (0);
		nb = top_a->data;
		i++;
	}
	ft_delete_all_nodes_a(&stacks->top_a);
	exit (0);
}

void	ft_free_structure(t_stacks *stacks)
{
	ft_delete_all_nodes_a(&stacks->top_a);
	ft_delete_all_nodes_b(&stacks->top_b);
	free(stacks->actions);
	free(stacks->easy);
	free(stacks->ranges);
}
