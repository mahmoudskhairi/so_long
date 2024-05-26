/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:28:20 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/22 17:01:00 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_three(t_list **stack_a)
{
	if ((*stack_a)->index == 2 && (*stack_a)->next->index == 0
		&& (*stack_a)->next->next->index == 1)
		ra(stack_a);
	else if ((*stack_a)->index == 2 && (*stack_a)->next->index == 1
		&& (*stack_a)->next->next->index == 0)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index == 0
		&& (*stack_a)->next->next->index == 2)
		sa(stack_a);
	else if ((*stack_a)->index == 1 && (*stack_a)->next->index == 2
		&& (*stack_a)->next->next->index == 0)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	rra_time;
	int	iter;

	iter = ft_search_max(stack_a);
	size = ft_lstsize(*stack_a);
	rra_time = size - iter;
	if (iter <= size / 2)
	{
		while (iter--)
			ra(stack_a);
	}
	else
	{
		while (rra_time--)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	if (!ft_is_sorted(stack_a))
		ft_sort_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	rra_time;
	int	iter;

	iter = ft_search_max(stack_a);
	size = ft_lstsize(*stack_a);
	rra_time = size - iter;
	if (iter <= size / 2)
	{
		while (iter--)
			ra(stack_a);
	}
	else
	{
		while (rra_time--)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	if (!ft_is_sorted(stack_a))
		ft_sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}
