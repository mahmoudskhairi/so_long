/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:43:11 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/25 18:30:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstprev(t_list *stack_a)
{
	if (!stack_a)
	{
		return (stack_a);
	}
	while (stack_a->next)
	{
		if (stack_a->next->next == NULL)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (stack_a);
}
