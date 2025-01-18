/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:24:56 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/09 11:25:08 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_new_max_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->actions->ra = 0;
	stacks->actions->rra = 0;
	if (ft_lstlast_a(stacks->top_a)->data != stacks->ranges->max_a)
	{
		i = ft_find_index_stack_a(stacks, stacks->ranges->max_a);
		size = ft_lstsize_a(stacks->top_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->actions->rra = (size - i) - 1;
			else
				stacks->actions->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				stacks->actions->rra = (size - i) - 1;
			else
				stacks->actions->ra = i + 1;
		}
	}
	ft_perform_moves_max_a(stacks);
}

void	ft_perform_moves_max_a(t_stacks *stacks)
{
	while (stacks->actions->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->actions->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
	ft_rotate(stacks, 'a');
}

void	ft_put_new_min_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->actions->ra = 0;
	stacks->actions->rra = 0;
	if (stacks->top_a->data != stacks->ranges->min_a)
	{
		i = ft_find_index_stack_a(stacks, stacks->ranges->min_a);
		size = ft_lstsize_a(stacks->top_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->actions->rra = (size - i);
			else
				stacks->actions->ra = i;
		}
		else
		{
			if (i > size / 2)
				stacks->actions->rra = (size - i);
			else
				stacks->actions->ra = i;
		}
	}
	ft_perform_moves_min_a(stacks);
}

void	ft_perform_moves_min_a(t_stacks *stacks)
{
	while (stacks->actions->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->actions->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}
