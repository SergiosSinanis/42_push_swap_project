/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:26:26 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/09 11:26:40 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_new_number_in_a(t_stacks *stacks, t_stack_b *top_b)
{
	int	i;
	int	size;

	stacks->actions->ra = 0;
	stacks->actions->rra = 0;
	if (stacks->top_a->data != ft_search_a(stacks, top_b->data))
	{
		i = ft_find_index_stack_a(stacks, ft_search_a(stacks, top_b->data));
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
	ft_perform_moves_number_stack_a(stacks);
}

void	ft_perform_moves_number_stack_a(t_stacks *stacks)
{
	while (stacks->actions->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->actions->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

int	ft_search_a(t_stacks *stacks, int nbr)
{
	t_stack_a	*top_a;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	top_a = stacks->top_a;
	size = ft_lstsize_a(stacks->top_a);
	while (flag == 0)
	{
		i = 0;
		nbr++;
		top_a = stacks->top_a;
		while (i++ < size)
		{
			if (top_a->data == nbr)
				flag = 1;
			top_a = top_a->next;
		}
	}
	return (nbr);
}

void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}
