/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:07:13 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/13 15:40:36 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_parse_input(int argc, char *argv[], int *arg_count)
{
	if (argc == 1)
		exit(0);
	if (argc == 2)
		return (ft_parse_input_split(argv[1], arg_count));
	else
	{
		*arg_count = argc - 1;
		ft_is_input_only_ints(argc - 1, argv + 1);
		ft_is_input_in_int_limits(argc - 1, argv + 1);
		return (argv + 1);
	}
}

char	**ft_parse_input_split(char *arg, int *arg_count)
{
	char	**split_args;

	split_args = NULL;
	split_args = ft_split(arg, ' ');
	if (split_args)
	{
		*arg_count = 0;
		while (split_args[*arg_count])
			(*arg_count)++;
	}
	else
	{
		ft_print_error();
		return (NULL);
	}
	if (*arg_count == 0)
		ft_print_error();
	ft_is_input_only_ints(*arg_count, split_args);
	ft_is_input_in_int_limits(*arg_count, split_args);
	return (split_args);
}

void	ft_is_input_only_ints(int arg_count, char *argv[])
{
	int	i;

	i = 0;
	while (i < arg_count)
	{
		ft_check_empty_arg(argv[i]);
		i++;
	}
}

void	ft_is_input_in_int_limits(int argc, char *argv[])
{
	long	nb;
	int		i;

	i = 0;
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_print_error();
		i++;
	}
}

void	ft_check_double_numbers_in_stack(t_stack_a *top_a)
{
	t_stack_a	*aide;
	t_stack_a	*current;
	int			nb;

	current = top_a;
	while (current != NULL)
	{
		aide = current;
		nb = aide->data;
		aide = aide->next;
		while (aide != NULL)
		{
			if (nb == aide->data)
			{
				ft_putstr_fd("Error\n", 2);
				ft_delete_all_nodes_a(&top_a);
				exit (0);
			}
			aide = aide->next;
		}
		current = current->next;
	}
}
