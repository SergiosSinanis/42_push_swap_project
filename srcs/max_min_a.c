/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:28:49 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/09 10:29:05 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_max_min_a(t_stacks *stacks)
{
	ft_max_a(stacks, stacks->top_a);
	ft_min_a(stacks, stacks->top_a);
}

void	ft_max_a(t_stacks *stacks, t_stack_a *top_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_a(top_a);
	stacks->ranges->max_a = top_a->data;
	while (i < size)
	{
		if (stacks->ranges->max_a < top_a->data)
			stacks->ranges->max_a = top_a->data;
		top_a = top_a->next;
		i++;
	}
}

void	ft_min_a(t_stacks *stacks, t_stack_a *top_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_a(top_a);
	stacks->ranges->min_a = top_a->data;
	while (i < size)
	{
		if (stacks->ranges->min_a > top_a->data)
			stacks->ranges->min_a = top_a->data;
		top_a = top_a->next;
		i++;
	}
}
