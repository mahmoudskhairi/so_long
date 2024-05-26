/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:01:08 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/29 12:17:54 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(t_list **stack_a)
{
	t_list	*tmp1;

	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp1 = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp1->next = (*stack_a)->next;
		(*stack_a)->next = tmp1;
		ft_putendl_fd("sa", 1);
	}
}

void	sb(t_list **stack_b)
{
	t_list	*tmp1;

	if (ft_lstsize(*stack_b) >= 2)
	{
		tmp1 = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp1->next = (*stack_b)->next;
		(*stack_b)->next = tmp1;
		ft_putendl_fd("sb", 1);
	}
}

static void	swap_nodes(t_list **stack)
{
	t_list	*tmp1;

	if (ft_lstsize(*stack) >= 2)
	{
		tmp1 = *stack;
		*stack = (*stack)->next;
		tmp1->next = (*stack)->next;
		(*stack)->next = tmp1;
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	ft_putendl_fd("ss", 1);
}
