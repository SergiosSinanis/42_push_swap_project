/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewer_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:53:46 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/09 10:53:59 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fewer_actions(t_stacks *stacks)
{
	t_actions	*actions;
	t_easy		*easy;
	t_ranges	*ranges;

	actions = ft_calloc(1, sizeof(t_actions));
	stacks->actions = actions;
	easy = ft_calloc(1, sizeof(t_easy));
	stacks->easy = easy;
	ranges = ft_calloc(1, sizeof(t_ranges));
	stacks->ranges = ranges;
	while (ft_lstsize_a(stacks->top_a) != 3)
	{
		ft_max_min_b(stacks);
		ft_check_moves(stacks);
		ft_perform_best_moves(stacks);
	}
}

void	ft_perform_best_moves(t_stacks *stacks)
{
	while (stacks->easy->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->easy->rb-- != 0)
		ft_rotate(stacks, 'b');
	while (stacks->easy->rr-- != 0)
		ft_rotate(stacks, 'r');
	while (stacks->easy->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	while (stacks->easy->rrb-- != 0)
		ft_rev_rotate(stacks, 'b');
	while (stacks->easy->rrr-- != 0)
		ft_rev_rotate(stacks, 'r');
	while (stacks->easy->pb-- != 0)
		ft_push(stacks, 'b');
}

void	ft_check_moves(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack_a	*top_a;

	top_a = stacks->top_a;
	size = ft_lstsize_a(stacks->top_a);
	i = 0;
	while (i++ < size)
	{
		ft_get_top_stack_a(stacks, top_a, i - 1);
		if (top_a->data > stacks->ranges->max_b
			|| top_a->data < stacks->ranges->min_b)
			ft_new_max_or_min_stack_b(stacks);
		else
			ft_new_nb_in_stack_b(stacks, top_a->data);
		ft_check_double_moves(stacks);
		ft_check_cost(stacks, i);
		top_a = top_a->next;
	}
}

void	ft_check_cost(t_stacks *stacks, int i)
{
	stacks->actions->cost = stacks->actions->pb + stacks->actions->ra
		+ stacks->actions->rb + stacks->actions->rr + stacks->actions->rra
		+ stacks->actions->rrb + stacks->actions->rrr;
	if (i == 1 || (stacks->easy->cost > stacks->actions->cost))
	{
		stacks->easy->cost = stacks->actions->cost;
		stacks->easy->pb = stacks->actions->pb;
		stacks->easy->ra = stacks->actions->ra;
		stacks->easy->rb = stacks->actions->rb;
		stacks->easy->rr = stacks->actions->rr;
		stacks->easy->rra = stacks->actions->rra;
		stacks->easy->rrb = stacks->actions->rrb;
		stacks->easy->rrr = stacks->actions->rrr;
	}
}

void	ft_check_double_moves(t_stacks *stacks)
{
	stacks->actions->rr = 0;
	stacks->actions->rrr = 0;
	while (stacks->actions->ra != 0 && stacks->actions->rb != 0)
	{
		stacks->actions->ra--;
		stacks->actions->rb--;
		stacks->actions->rr++;
	}
	while (stacks->actions->rra != 0 && stacks->actions->rrb != 0)
	{
		stacks->actions->rra--;
		stacks->actions->rrb--;
		stacks->actions->rrr++;
	}
}
