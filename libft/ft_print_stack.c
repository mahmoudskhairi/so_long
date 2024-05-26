/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:06:12 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/28 13:19:31 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_stack_b(t_list *tmp)
{
	if (!tmp)
		ft_putendl_fd("invalid stack_b", 1);
	else
	{
		ft_putendl_fd("\nstack_b:", 1);
		if (!tmp->next)
			printf("[%d] =  %d\n", tmp->index, tmp->content);
		while (tmp->next)
		{
			printf("[%d] =  %d\n", tmp->index, tmp->content);
			tmp = tmp->next;
			if (!tmp->next)
			{
				printf("[%d] =  %d\n", tmp->index, tmp->content);
				break ;
			}
		}
	}
}

void	ft_print_stack(t_list *tmp1, t_list *tmp2)
{
	if (!tmp1)
		ft_putendl_fd("invalid stack_a\n", 1);
	else
	{
		ft_putendl_fd("stack_a:", 1);
		if (!tmp1->next)
			printf("[%d] =  %d\n", tmp1->index, tmp1->content);
		while (tmp1->next)
		{
			printf("[%d] =  %d\n", tmp1->index, tmp1->content);
			tmp1 = tmp1->next;
			if (!tmp1->next)
			{
				printf("[%d] =  %d\n", tmp1->index, tmp1->content);
				break ;
			}
		}
	}
	ft_print_stack_b(tmp2);
}
