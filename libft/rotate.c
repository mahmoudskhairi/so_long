/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:14:20 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/29 12:17:38 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ra(t_list **stack_a)
{
	t_list	*first_node;
	t_list	*last_node;

	if (ft_lstsize(*stack_a) >= 2)
	{
		first_node = *stack_a;
		*stack_a = (*stack_a)->next;
		last_node = ft_lstlast(*stack_a);
		last_node->next = first_node;
		first_node->next = NULL;
		ft_putendl_fd("ra", 1);
	}
}

void	rb(t_list **stack_b)
{
	t_list	*first_node;
	t_list	*last_node;

	if (ft_lstsize(*stack_b) >= 2)
	{
		first_node = *stack_b;
		*stack_b = (*stack_b)->next;
		last_node = ft_lstlast(*stack_b);
		last_node->next = first_node;
		first_node->next = NULL;
		ft_putendl_fd("rb", 1);
	}
}

static void	rotate_nodes(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (ft_lstsize(*stack) >= 2)
	{
		first_node = *stack;
		*stack = (*stack)->next;
		last_node = ft_lstlast(*stack);
		last_node->next = first_node;
		first_node->next = NULL;
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	ft_putendl_fd("rr", 1);
}
