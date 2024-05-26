/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:46:17 by mskhairi          #+#    #+#             */
/*   Updated: 2024/02/16 10:59:10 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list pa)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(pa, int));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(pa, int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(pa, unsigned int));
	else if (c == 's')
		count += ft_putstr(va_arg(pa, char *));
	else if (c == 'p')
		count += ft_putadd(va_arg(pa, void *));
	else if (c == 'x')
		count += ft_puthexa(va_arg(pa, unsigned int), c);
	else if (c == 'X')
		count += ft_puthexa(va_arg(pa, unsigned int), c);
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (count);
			count += ft_format(s[++i], args);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
