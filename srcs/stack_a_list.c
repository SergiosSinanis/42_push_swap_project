/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:17:03 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/10 10:23:45 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a	*ft_create_stack_a(int count, char **args)
{
	int			i;
	t_stack_a	*top_a;
	t_stack_a	*aide;

	if (count <= 0)
		return (NULL);
	top_a = ft_new_node_a(ft_atoi(args[0]));
	aide = top_a;
	i = 1;
	while (i < count)
	{
		aide->next = ft_new_node_a(ft_atoi(args[i]));
		if (!aide->next)
		{
			ft_delete_all_nodes_a(&top_a);
			write(2, "Error\n", 6);
			exit(1);
		}
		aide = aide->next;
		i++;
	}
	return (top_a);
}

t_stack_a	*ft_new_node_a(int data)
{
	t_stack_a	*new;

	new = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_delete_all_nodes_a(t_stack_a **lst)
{
	t_stack_a	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp->next;
		free (tmp);
	}
}

int	ft_lstsize_a(t_stack_a *top)
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

t_stack_a	*ft_lstlast_a(t_stack_a *top_a)
{
	if (top_a == NULL)
		return (NULL);
	while (top_a->next != NULL)
		top_a = top_a->next;
	return (top_a);
}
