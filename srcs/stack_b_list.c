/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:17:03 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/05 13:06:31 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_b	*ft_create_stack_b(int argc, char *argv[])
{
	int			i;
	t_stack_b	*top_b;
	t_stack_b	*aide;

	i = 1;
	top_b = ft_new_node_b(ft_atoi(argv[i]));
	aide = top_b;
	i++;
	while (i < argc)
	{
		aide->next = ft_new_node_b(ft_atoi(argv[i]));
		aide = aide->next;
		aide->next = NULL;
		i++;
	}
	return (top_b);
}

t_stack_b	*ft_new_node_b(int data)
{
	t_stack_b	*new;

	new = (t_stack_b *)malloc(sizeof(t_stack_b));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_delete_all_nodes_b(t_stack_b **lst)
{
	t_stack_b	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp->next;
		free (tmp);
	}
}

int	ft_lstsize_b(t_stack_b *top)
{
	int		counter;

	counter = 0;
	while (top != NULL)
	{
		counter++;
		top = top->next;
	}
	return (counter);
}

t_stack_b	*ft_lstlast_b(t_stack_b *top_b)
{
	if (top_b == NULL)
		return (NULL);
	while (top_b->next != NULL)
		top_b = top_b->next;
	return (top_b);
}
