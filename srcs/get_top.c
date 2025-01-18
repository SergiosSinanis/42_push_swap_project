/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:10:15 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/09 11:10:28 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_top_stack_a(t_stacks *stacks, t_stack_a *top_a, int i)
{
	int	size;

	stacks->actions->pb = 1;
	stacks->actions->ra = 0;
	stacks->actions->rra = 0;
	if (stacks->top_a->data == top_a->data)
		return ;
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

void	ft_new_max_or_min_stack_b(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->actions->rb = 0;
	stacks->actions->rrb = 0;
	if (stacks->top_b->data == stacks->ranges->max_b)
		return ;
	i = ft_find_index_stack_b(stacks, stacks->ranges->max_b);
	size = ft_lstsize_b(stacks->top_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->actions->rrb = (size - i);
		else
			stacks->actions->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->actions->rrb = (size - i);
		else
			stacks->actions->rb = i;
	}
}

void	ft_new_nb_in_stack_b(t_stacks *stacks, int nb)
{
	int	i;
	int	size;
	int	nbr;

	stacks->actions->rb = 0;
	stacks->actions->rrb = 0;
	nbr = ft_search_nb_in_stack_b(stacks, nb);
	if (stacks->top_b->data == nbr)
		return ;
	i = ft_find_index_stack_b(stacks, nbr);
	size = ft_lstsize_b(stacks->top_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->actions->rrb = (size - i);
		else
			stacks->actions->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->actions->rrb = (size - i);
		else
			stacks->actions->rb = i;
	}
}

int	ft_search_nb_in_stack_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*top_b;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	top_b = stacks->top_b;
	size = ft_lstsize_b(stacks->top_b);
	while (flag == 0)
	{
		i = 0;
		nbr--;
		top_b = stacks->top_b;
		while (i++ < size)
		{
			if (top_b->data == nbr)
				flag = 1;
			top_b = top_b->next;
		}
	}
	return (nbr);
}
