/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:14:23 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/22 12:24:58 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	first_node = *stack_b;
	if (!first_node)
		return ;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, first_node);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	first_node = *stack_a;
	if (!first_node)
		return ;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, first_node);
	ft_putendl_fd("pb", 1);
}
