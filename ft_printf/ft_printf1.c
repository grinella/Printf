/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:24:14 by grinella          #+#    #+#             */
/*   Updated: 2023/02/09 10:31:28 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
		(*count) += write(1, "(null)", 6);
	else
		(*count) += write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n, int *count)
{
	char	c;

	if (n == -2147483648)
	{
		(*count) += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		(*count) += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr((n / 10), count);
	c = n % 10 + '0';
	(*count) += write(1, &c, 1);
}

void	ft_putchar(char c, int *count)
{
	(*count) += write(1, &c, 1);
}

void	ft_puthex(unsigned int n, int *count)
{
	char	*hex_digits;
	char	c;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_puthex((n / 16), count);
	c = hex_digits[n % 16];
	(*count) += write(1, &c, 1);
}
