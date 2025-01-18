/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:10:53 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/06 11:45:01 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, char c)
{
	t_stack_a	*top_a;
	t_stack_b	*top_b;

	top_a = stacks->top_a;
	top_b = stacks->top_b;
	if (c == 'a')
		ft_swap_a(top_a, 1);
	else if (c == 'b')
	{
		if (top_b == NULL || top_b->next == NULL)
			return ;
		ft_swap_b(top_b, 1);
	}
	else
	{
		if (top_a == NULL || top_a->next == NULL
			|| top_b == NULL || top_b->next == NULL)
			return ;
		ft_swap_a(top_a, 0);
		ft_swap_b(top_b, 0);
		ft_printf("ss\n");
	}
}

void	ft_swap_a(t_stack_a *top_a, int print_flag)
{
	int	tmp;

	tmp = top_a->data;
	top_a->data = top_a->next->data;
	top_a->next->data = tmp;
	if (print_flag != 0)
		ft_printf("sa\n");
}

void	ft_swap_b(t_stack_b *top_b, int print_flag)
{
	int	tmp;

	tmp = top_b->data;
	top_b->data = top_b->next->data;
	top_b->next->data = tmp;
	if (print_flag != 0)
		ft_printf("sb\n");
}
