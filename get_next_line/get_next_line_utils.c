/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:19 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/29 10:15:01 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_malloc(size_t count, size_t size)
{
	size_t	bytes;
	size_t	i;
	char	*p;

	i = 0;
	bytes = count * size;
	if (size && bytes / size != count)
		return (NULL);
	p = malloc(bytes);
	if (!p)
		return (NULL);
	while (i < bytes)
	{
		*(p + i) = 0;
		i++;
	}
	return (p);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*str;
	int		join_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*s2)
		return (s1);
	join_len = ft_len(s1) + ft_len(s2);
	str = ft_malloc((join_len + 1), 1);
	if (!str)
	{
		ft_free_(&s1, NULL);
		return (NULL);
	}
	while (s1 && s1[i])
		str[i++] = s1[j++];
	ft_free_(&s1, NULL);
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	return (str);
}

int	ft_str_newline(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}
