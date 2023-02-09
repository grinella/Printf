/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:10:57 by grinella          #+#    #+#             */
/*   Updated: 2023/02/09 10:47:38 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, format);
	if (format == 0)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_switch(ap, format, i, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	return (count);
}

void	ft_switch(va_list ap, const char *format, int i, int *count)
{
	if (format[i] == 's')
		ft_putstr(va_arg(ap, char *), count);
	if (format[i] == 'c')
		ft_putchar(va_arg(ap, int), count);
	if (format[i] == '%')
		ft_putchar('%', count);
	if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(ap, int), count);
	if (format[i] == 'x')
		ft_puthex(va_arg(ap, unsigned int), count);
	if (format[i] == 'X')
		ft_puthexx(va_arg(ap, unsigned int), count);
	if (format[i] == 'p')
		ft_putint(va_arg(ap, unsigned long long), count);
	if (format[i] == 'u')
		ft_putunsdec(va_arg(ap, unsigned int), count);
}
/*
int	main(void)
{
	int		a;
	char	c;

	c = 'a';
	a = ft_printf ("%p", &c);
	printf("\n count = %d", a);
	printf("%p", &c);
}
*/