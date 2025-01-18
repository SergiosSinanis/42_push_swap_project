/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:57:17 by ssinanis          #+#    #+#             */
/*   Updated: 2024/11/12 16:48:21 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_l(char c, int *length)
{
	write (1, &c, 1);
	(*length)++;
}

void	ft_specifier(char c, va_list *my_args, int *length)
{
	if (c == 'c')
		ft_putchar_l(va_arg(*my_args, int), length);
	else if (c == 's')
		ft_putstr2(va_arg(*my_args, char *), length);
	else if (c == 'p')
		ft_putpointer(va_arg(*my_args, size_t), length);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*my_args, int), length);
	else if (c == 'u')
		ft_putunsigned(va_arg(*my_args, unsigned int), length);
	else if (c == 'x')
		ft_16print(va_arg(*my_args, unsigned int), length, 'x');
	else if (c == 'X')
		ft_16print(va_arg(*my_args, unsigned int), length, 'X');
	else if (c == '%')
		ft_putchar_l('%', length);
	else
	{
		ft_putchar_l('%', length);
		ft_putchar_l(c, length);
	}
}

int	ft_printf(const char *specifier, ...)
{
	va_list	my_args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(my_args, specifier);
	while (specifier[i])
	{
		if (specifier[i] == '%')
		{
			i++;
			ft_specifier(specifier[i], &my_args, &length);
		}
		else
			ft_putchar_l(specifier[i], &length);
		i++;
	}
	va_end(my_args);
	return (length);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
