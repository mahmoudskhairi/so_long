/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:38:44 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/30 16:27:55 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_creat_sort_arr(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	i = 0;
	while (stack)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	ft_sort_tab(arr, size);
	return (arr);
}

void	ft_set_index(int *tab, t_list **stack, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == tab[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_indexing(t_list **stack)
{
	int		*tab;
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*stack);
	tmp = *stack;
	tab = ft_creat_sort_arr(tmp, size);
	ft_set_index(tab, stack, size);
	free(tab);
}
