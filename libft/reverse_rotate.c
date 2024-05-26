/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:28:57 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/29 12:17:20 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rra(t_list **stack_a)
{
	t_list	*first_node;
	t_list	*prev_node;
	t_list	*last_node;

	if (ft_lstsize(*stack_a) >= 2)
	{
		first_node = *stack_a;
		prev_node = ft_lstprev(*stack_a);
		last_node = ft_lstlast(*stack_a);
		*stack_a = last_node;
		last_node->next = first_node;
		prev_node->next = NULL;
		ft_putendl_fd("rra", 1);
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*first_node;
	t_list	*prev_node;
	t_list	*last_node;

	if (ft_lstsize(*stack_b) >= 2)
	{
		first_node = *stack_b;
		prev_node = ft_lstprev(*stack_b);
		last_node = ft_lstlast(*stack_b);
		*stack_b = last_node;
		last_node->next = first_node;
		prev_node->next = NULL;
		ft_putendl_fd("rrb", 1);
	}
}

static void	reverce_rotate_stack(t_list **stack)
{
	t_list	*first_node;
	t_list	*prev_node;
	t_list	*last_node;

	if (ft_lstsize(*stack) >= 2)
	{
		first_node = *stack;
		prev_node = ft_lstprev(*stack);
		last_node = ft_lstlast(*stack);
		*stack = last_node;
		last_node->next = first_node;
		prev_node->next = NULL;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverce_rotate_stack(stack_a);
	reverce_rotate_stack(stack_b);
	ft_putendl_fd("rrr", 1);
}
