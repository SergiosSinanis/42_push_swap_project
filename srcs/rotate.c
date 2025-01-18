/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:50:50 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/06 12:04:17 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stacks *stacks, char c)
{
	t_stack_a	*top_a;
	t_stack_b	*top_b;

	top_a = stacks->top_a;
	top_b = stacks->top_b;
	if (c == 'a')
		ft_rotate_a(stacks, stacks->top_a, 1);
	else if (c == 'b')
	{
		if (top_b == NULL || top_b->next == NULL)
			return ;
		ft_rotate_b(stacks, top_b, 1);
	}
	else
	{
		if (top_a == NULL || top_a->next == NULL
			|| top_b == NULL || top_b->next == NULL)
			return ;
		ft_rotate_a(stacks, stacks->top_a, 0);
		ft_rotate_b(stacks, top_b, 0);
		ft_printf("rr\n");
	}
}

void	ft_rotate_a(t_stacks *stacks, t_stack_a *top_a, int print_flag)
{
	t_stack_a	*tmp_top;

	tmp_top = top_a;
	stacks->top_a = top_a->next;
	while (top_a->next != NULL)
		top_a = top_a->next;
	top_a->next = tmp_top;
	tmp_top->next = NULL;
	if (print_flag != 0)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_stacks *stacks, t_stack_b *top_b, int print_flag)
{
	t_stack_b	*tmp_top;

	tmp_top = top_b;
	stacks->top_b = top_b->next;
	while (top_b->next != NULL)
		top_b = top_b->next;
	top_b->next = tmp_top;
	tmp_top->next = NULL;
	if (print_flag != 0)
		ft_printf("rb\n");
}
