/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:11:57 by grinella          #+#    #+#             */
/*   Updated: 2023/02/09 10:46:50 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *s, int *count);
void	ft_switch(va_list ap, const char *format, int i, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_puthex(unsigned int n, int *count);
void	ft_puthexx(unsigned int n, int *count);
int		ft_putint(unsigned long long n, int *count);
void	ft_putunsdec(unsigned int n, int *count);
void	ft_puthex_p(unsigned long long n, int *count);

#endif
