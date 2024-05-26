/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:54:19 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/21 16:39:12 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		join_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	if (!*s2)
		return (s1);
	join_len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(join_len + 1, 1);
	if (!str)
	{
		ft_free(&s1);
		ft_free(&s2);
		return (NULL);
	}
	while (s1 && s1[i])
		str[i++] = s1[j++];
	ft_free(&s1);
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	return (str);
}
