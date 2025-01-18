/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:22:51 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/09 10:24:49 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_all_back_to_a(t_stacks *stacks)
{
	while (stacks->top_b != NULL)
	{
		ft_max_min_a(stacks);
		if (stacks->top_b->data < stacks->ranges->min_a)
			ft_put_new_min_a(stacks);
		else if (stacks->top_b->data > stacks->ranges->max_a)
			ft_put_new_max_a(stacks);
		else
			ft_put_new_number_in_a(stacks, stacks->top_b);
	}
	ft_max_min_a(stacks);
	ft_order(stacks);
}

void	ft_order(t_stacks *stacks)
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
	ft_perform_rotations(stacks);
}

void	ft_perform_rotations(t_stacks *stacks)
{
	while (stacks->actions->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->actions->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
}

int	ft_find_index_stack_a(t_stacks *stacks, int nbr)
{
	t_stack_a	*top_a;
	int			size;
	int			i;

	i = 0;
	top_a = stacks->top_a;
	size = ft_lstsize_a(stacks->top_a);
	while (i < size)
	{
		if (top_a->data == nbr)
			break ;
		top_a = top_a->next;
		i++;
	}
	return (i);
}

int	ft_find_index_stack_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*top_b;
	int			size;
	int			i;

	i = 0;
	top_b = stacks->top_b;
	size = ft_lstsize_b(stacks->top_b);
	while (i < size)
	{
		if (top_b->data == nbr)
			break ;
		top_b = top_b->next;
		i++;
	}
	return (i);
}
