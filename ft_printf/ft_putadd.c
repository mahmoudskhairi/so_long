/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:05:20 by mskhairi          #+#    #+#             */
/*   Updated: 2024/02/16 10:58:37 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add(unsigned long n)
{
	int		count;
	char	*s;

	count = 0;
	s = "0123456789abcdef";
	if (n < 16)
		count += ft_putchar(s[n]);
	else
	{
		count += ft_add(n / 16);
		count += ft_putchar(s[n % 16]);
	}
	return (count);
}

int	ft_putadd(void *p)
{
	unsigned long	nb;
	int				count;

	count = 0;
	nb = (unsigned long)p;
	count += ft_putstr("0x");
	count += ft_add(nb);
	return (count);
}
