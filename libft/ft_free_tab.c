/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:54:34 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/22 15:28:58 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(int **tab1, int **tab2)
{
	if (tab1)
	{
		free(*tab1);
		*tab1 = NULL;
	}
	if (tab2)
	{
		free(*tab2);
		*tab2 = NULL;
	}
}