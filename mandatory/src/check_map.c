/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:30:27 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/26 06:35:14 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_lines(char **map)
{
	int	newlen;
	int	oldlen;
	int	i;

	i = 0;
	oldlen = 0;
	while (map[i])
	{
		newlen = ft_strlen(map[i++]);
		if (i > 1 && oldlen != newlen)
			ft_print_error("Error\ninvalid map!");
		oldlen = newlen;
	}
}

void	ft_first_last_line(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != WALL)
			ft_print_error("Error\ninvalid perimeter!");
		j++;
	}
}

void	ft_check_perimeter(char **map)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (map[i++])
		lines++;
	i = 0;
	ft_first_last_line(map, 0);
	while (map[i])
	{
		if (map[i][0] != WALL || map[i][ft_strlen(map[i]) - 1] != WALL)
			ft_print_error("Error\ninvalid perimeter!");
		i++;
	}
	ft_first_last_line(map, lines - 1);
}

int	*ft_position(char **map, char c)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * 2);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				tab[0] = i;
				tab[1] = j;
				return (tab);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

void	ft_check_maps(char **map)
{
	t_component	component;
	int			*position;

	ft_check_lines(map);
	ft_check_perimeter(map);
	ft_init_comp(&component);
	ft_check_components(map, &component);
	position = ft_position(map, PLAYER);
	ft_fload_fill(map, position[0], position[1]);
	ft_free_tab(&position, 0);
	check_comp(map);
	ft_free_array(map);
}
