/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:40:55 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 19:40:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;

	i = 0;
	if (size >= 2)
	{
		while (i <= size - 2)
		{
			j = i + 1;
			while (j <= size - 1)
			{
				if (tab[i] > tab[j])
				{
					tmp = tab[i];
					tab[i] = tab[j];
					tab[j] = tmp;
				}
				j++;
			}
			i++;
		}
	}
}
