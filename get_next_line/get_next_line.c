/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:14:58 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/29 10:12:19 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_(char **s1, char **s2)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

char	*ft_next(char *str, char **new_line)
{
	char	*next;
	int		index;
	int		i;

	i = 0;
	index = 0;
	index = ft_str_newline(str, '\n');
	if (index == -1)
		return (NULL);
	if (str[index + 1] == 0)
	{
		ft_free_(&str, NULL);
		return (NULL);
	}
	index++;
	next = ft_malloc(ft_len(str + index) + 1, 1);
	if (!next)
	{
		ft_free_(&str, new_line);
		return (NULL);
	}
	while (str[index])
		next[i++] = str[index++];
	ft_free_(&str, NULL);
	return (next);
}

char	*ft_new_line(char *str)
{
	char	*new_line;
	int		index;

	if (!str || !*str)
		return (NULL);
	index = ft_str_newline(str, '\n');
	if (index == -1)
		return (str);
	else
	{
		index++;
		new_line = ft_malloc(index + 1, 1);
		if (!new_line)
			return (NULL);
	}
	while (index--)
		new_line[index] = str[index];
	return (new_line);
}

void	ft_readalloc(int fd, char **next)
{
	char	*buff;
	ssize_t	r;

	r = 1;
	buff = ft_malloc(BUFFER_SIZE + 1, 1);
	if (!buff)
	{
		ft_free_(next, NULL);
		return ;
	}
	while (ft_str_newline(buff, '\n') == -1 && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_(next, NULL);
			break ;
		}
		buff[r] = '\0';
		*next = ft_str_join(*next, buff);
		if (!*next)
			break ;
	}
	ft_free_(&buff, NULL);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*next;

	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_readalloc(fd, &next);
	if (!next)
		return (NULL);
	new_line = ft_new_line(next);
	if (!new_line)
	{
		ft_free_(&next, NULL);
		return (NULL);
	}
	next = ft_next(next, &new_line);
	return (new_line);
}
