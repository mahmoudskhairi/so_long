/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:20:38 by mskhairi          #+#    #+#             */
/*   Updated: 2024/01/20 10:57:32 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_puthexa(unsigned int n, char format)
{
	int		count;
	char	*s;

	s = "0123456789abcdef";
	count = 0;
	if (format == 'X')
		s = "0123456789ABCDEF";
	if (n < 16)
		count += ft_putchar(s[n]);
	else
	{
		count += ft_puthexa(n / 16, format);
		count += ft_putchar(s[n % 16]);
	}
	return (count);
}
