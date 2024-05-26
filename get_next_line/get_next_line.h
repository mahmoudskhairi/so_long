/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:16:29 by mskhairi          #+#    #+#             */
/*   Updated: 2024/04/29 10:11:51 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	ft_readalloc(int fd, char **next);
char	*ft_new_line(char *str);
char	*ft_next(char *str, char **new_line);
int		ft_str_newline(char *s, int c);
char	*ft_str_join(char *s1, char *s2);
void	*ft_malloc(size_t count, size_t size);
void	ft_free_(char **s1, char **s2);
size_t	ft_len(char *s);
#endif