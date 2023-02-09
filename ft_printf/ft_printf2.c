/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:38:30 by grinella          #+#    #+#             */
/*   Updated: 2023/02/09 10:46:29 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexx(unsigned int n, int *count)
{
	char	*hex_digits;
	char	c;

	hex_digits = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthexx((n / 16), count);
	c = hex_digits[n % 16];
	(*count) += write(1, &c, 1);
}

int	ft_putint(unsigned long long n, int *count)
{
	ft_putstr("0x", count);
	ft_puthex_p(n, count);
	return (*count);
}

void	ft_putunsdec(unsigned int n, int *count)
{
	char	c;

	if (n >= 10)
		ft_putnbr((n / 10), count);
	c = n % 10 + '0';
	(*count) += write(1, &c, 1);
}

void	ft_puthex_p(unsigned long long n, int *count)
{
	char	*hex_digits;
	char	c;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		ft_puthex_p((n / 16), count);
	c = hex_digits[n % 16];
	(*count) += write(1, &c, 1);
}
