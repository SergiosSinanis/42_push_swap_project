/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:29:25 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/09 10:29:36 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_max_min_b(t_stacks *stacks)
{
	if (stacks->top_b != NULL)
	{
		ft_max_b(stacks, stacks->top_b);
		ft_min_b(stacks, stacks->top_b);
	}
}

void	ft_min_b(t_stacks *stacks, t_stack_b *top_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_b(top_b);
	stacks->ranges->min_b = top_b->data;
	while (i < size)
	{
		if (stacks->ranges->min_b > top_b->data)
			stacks->ranges->min_b = top_b->data;
		top_b = top_b->next;
		i++;
	}
}

void	ft_max_b(t_stacks *stacks, t_stack_b *top_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_b(top_b);
	stacks->ranges->max_b = top_b->data;
	while (i < size)
	{
		if (stacks->ranges->max_b < top_b->data)
			stacks->ranges->max_b = top_b->data;
		top_b = top_b->next;
		i++;
	}
}
