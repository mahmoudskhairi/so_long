/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:46:14 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/28 13:48:18 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search_max(t_list **stack_b)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		max;
	int		count;

	count = 0;
	tmp1 = *stack_b;
	tmp2 = *stack_b;
	max = tmp1->index;
	while (tmp1)
	{
		tmp1 = tmp1->next;
		if (tmp1 && max < tmp1->index)
		{
			max = tmp1->index;
		}
	}
	while (tmp2)
	{
		if (max == tmp2->index)
			break ;
		tmp2 = tmp2->next;
		count++;
	}
	return (count);
}

void	ft_push_to_a(t_list **stack_a, t_list **stack_b, int iter)
{
	int	size;
	int	rra_time;

	size = ft_lstsize(*stack_b);
	rra_time = size - iter;
	if (iter == 0)
	{
		pa(stack_a, stack_b);
		return ;
	}
	else
	{
		if (iter <= size / 2)
		{
			while (iter--)
				rb(stack_b);
		}
		else
		{
			while (rra_time--)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

t_sort	ft_init_range(int range)
{
	t_sort	sort;

	sort.min_range = 0;
	if (range == 15)
		sort.max_range = 15;
	else
		sort.max_range = range;
	sort.iter = 0;
	return (sort);
}

void	ft_range(t_list **stack_a, t_list **stack_b, int iter)
{
	while (*stack_b)
	{
		iter = ft_search_max(stack_b);
		ft_push_to_a(stack_a, stack_b, iter);
	}
}

void	ft_sort_stack(t_list **stack_a, t_list **stack_b, int range)
{
	t_sort	sort;

	sort = ft_init_range(range);
	while (*stack_a)
	{
		if ((*stack_a)->index >= sort.min_range
			&& (*stack_a)->index <= sort.max_range)
		{
			pb(stack_a, stack_b);
			sort.min_range++;
			sort.max_range++;
		}
		else if ((*stack_a)->index < sort.min_range)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			sort.min_range++;
			sort.max_range++;
		}
		else
			ra(stack_a);
	}
	ft_range(stack_a, stack_b, sort.iter);
}
