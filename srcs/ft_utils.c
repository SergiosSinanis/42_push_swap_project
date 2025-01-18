/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssinanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:27:38 by ssinanis          #+#    #+#             */
/*   Updated: 2024/11/14 14:54:43 by ssinanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr2(char *str, int *length)
{
	int	i;

	if (!str)
	{
		write (1, "(null)", 6);
		(*length) = (*length) + 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar_l(str[i], length);
		i++;
	}
}

void	ft_putnbr(int nbr, int *length)
{
	long	nb;

	nb = nbr;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*length) = (*length) + 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_l('-', length);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, length);
	ft_putchar_l((nb % 10) + '0', length);
}

void	ft_putunsigned(unsigned int u, int *length)
{
	if (u > 9)
		ft_putunsigned(u / 10, length);
	ft_putchar_l((u % 10) + '0', length);
}

void	ft_putpointer(size_t pointer, int *length)
{
	char	*base;
	char	aide[25];
	int		i;

	if (pointer == 0)
	{
		write (1, "(nil)", 5);
		(*length) = (*length) + 5;
		return ;
	}
	i = 0;
	base = "0123456789abcdef";
	write (1, "0x", 2);
	(*length) = (*length) + 2;
	while (pointer != 0)
	{
		aide[i] = base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i > 0)
	{
		ft_putchar_l(aide[i - 1], length);
		i--;
	}
}

void	ft_16print(unsigned int nb, int *length, char x_or_X)
{
	char	*base;
	char	aide[25];
	int		i;

	i = 0;
	if (x_or_X == 'x')
		base = "0123456789abcdef";
	else if (x_or_X == 'X')
		base = "0123456789ABCDEF";
	if (nb == 0)
	{
		ft_putchar_l('0', length);
		return ;
	}
	while (nb != 0)
	{
		aide[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	while (i > 0)
	{
		ft_putchar_l(aide[i - 1], length);
		i--;
	}
}
