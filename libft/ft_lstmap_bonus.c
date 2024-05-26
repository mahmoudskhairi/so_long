/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:02:23 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/21 12:05:46 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*head;
	t_list	*ret;
	int		d;

	head = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			d = f(lst->content);
			ret = ft_lstnew(d);
			if (!ret)
			{
				del(d);
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, ret);
			lst = lst->next;
		}
	}
	return (head);
}
