/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:08:50 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/06 13:44:27 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stacks *stacks, char c)
{
	t_stack_a	*top_a;
	t_stack_b	*top_b;

	top_a = stacks->top_a;
	top_b = stacks->top_b;
	if (c == 'a')
		ft_rev_rotate_a(stacks, stacks->top_a, 1);
	else if (c == 'b')
	{
		if (top_b == NULL || top_b->next == NULL)
			return ;
		ft_rev_rotate_b(stacks, top_b, 1);
	}
	else
	{
		if (top_a == NULL || top_a->next == NULL
			|| top_b == NULL || top_b->next == NULL)
			return ;
		ft_rev_rotate_a(stacks, stacks->top_a, 0);
		ft_rev_rotate_b(stacks, top_b, 0);
		ft_printf("rrr\n");
	}
}

void	ft_rev_rotate_a(t_stacks *stacks, t_stack_a *top_a, int print_flag)
{
	t_stack_a	*tmp;
	int			i;
	int			size;

	tmp = top_a;
	size = ft_lstsize_a(top_a);
	while (top_a->next != NULL)
		top_a = top_a->next;
	top_a->next = tmp;
	stacks->top_a = top_a;
	tmp = stacks->top_a;
	i = 0;
	while (i < (size - 1))
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	if (print_flag != 0)
		ft_printf("rra\n");
}

void	ft_rev_rotate_b(t_stacks *stacks, t_stack_b *top_b, int print_flag)
{
	t_stack_b	*tmp;
	int			i;
	int			size;

	tmp = top_b;
	size = ft_lstsize_b(top_b);
	while (top_b->next != NULL)
		top_b = top_b->next;
	top_b->next = tmp;
	stacks->top_b = top_b;
	tmp = stacks->top_b;
	i = 0;
	while (i < (size - 1))
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	if (print_flag != 0)
		ft_printf("rrb\n");
}
