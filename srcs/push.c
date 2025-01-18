/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:57:20 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/06 17:57:59 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stacks *stacks, char c)
{
	t_stack_b	*top_b;

	top_b = stacks->top_b;
	if (c == 'a')
	{
		if (top_b == NULL)
			return ;
		else if (top_b->next == NULL)
			ft_last_push_to_a(stacks);
		else
			ft_push_to_pop_a(stacks);
	}
	else if (c == 'b')
	{
		if (top_b == NULL)
			ft_push_to_empty_b(stacks);
		else
			ft_push_to_pop_b(stacks);
	}
}

void	ft_push_to_pop_a(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = stacks->top_a;
	stacks->top_a = (t_stack_a *)stacks->top_b;
	stacks->top_b = stacks->top_b->next;
	stacks->top_a->next = tmp;
	ft_printf("pa\n");
}

void	ft_push_to_pop_b(t_stacks *stacks)
{
	t_stack_b	*tmp;

	tmp = stacks->top_b;
	stacks->top_b = (t_stack_b *)stacks->top_a;
	stacks->top_a = stacks->top_a->next;
	stacks->top_b->next = tmp;
	ft_printf("pb\n");
}

void	ft_last_push_to_a(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = stacks->top_a;
	stacks->top_a = (t_stack_a *)stacks->top_b;
	stacks->top_a->next = tmp;
	stacks->top_b = NULL;
	ft_printf("pa\n");
}

void	ft_push_to_empty_b(t_stacks *stacks)
{
	stacks->top_b = (t_stack_b *)stacks->top_a;
	stacks->top_a = stacks->top_a->next;
	stacks->top_b->next = NULL;
	ft_printf("pb\n");
}
