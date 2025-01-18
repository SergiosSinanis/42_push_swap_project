/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:19:08 by ssinanis          #+#    #+#             */
/*   Updated: 2024/12/10 10:17:19 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	char		**parsed_args;
	int			arg_count;

	parsed_args = ft_parse_input(argc, argv, &arg_count);
	stacks.top_a = ft_create_stack_a(arg_count, parsed_args);
	stacks.top_b = NULL;
	if (argc == 2)
		ft_free_split(parsed_args);
	ft_check_double_numbers_in_stack(stacks.top_a);
	ft_sort_stacks(&stacks);
	ft_free_structure(&stacks);
	return (0);
}

void	ft_check_empty_arg(char *arg)
{
	if (!arg[0])
		return ;
	else
		ft_is_valid_number(arg);
}

void	ft_is_valid_number(char *arg)
{
	int	b;

	b = 0;
	while (arg[b])
	{
		if (!ft_isdigit(arg[b]))
		{
			if (b == 0 && (arg[b] == '-' || arg[b] == '+'))
			{
				b++;
				if (!arg[b])
					ft_print_error();
				continue ;
			}
			ft_print_error();
		}
		b++;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free (split[i++]);
	free (split);
}
