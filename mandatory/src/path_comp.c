/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_comp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:47:09 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/21 14:58:37 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COLLECTIBLE)
				collectibles++;
			j++;
		}
		i++;
	}
	return (collectibles);
}

void	ft_init_comp(t_component *component)
{
	component->exit = 0;
	component->player = 0;
	component->collectible = 0;
	component->i = 0;
	component->j = 0;
}

void	ft_check_components(char **map, t_component *component)
{
	while (map[component->i])
	{
		while (map[component->i][component->j])
		{
			if (map[component->i][component->j] != EXIT
				&& map[component->i][component->j] != SPACE
				&& map[component->i][component->j] != WALL
				&& map[component->i][component->j] != COLLECTIBLE
				&& map[component->i][component->j] != PLAYER)
				ft_print_error("Error\ninvalid map!");
			else if (map[component->i][component->j] == EXIT)
				component->exit++;
			else if (map[component->i][component->j] == PLAYER)
				component->player++;
			else if (map[component->i][component->j] == COLLECTIBLE)
				component->collectible++;
			component->j++;
		}
		component->j = 0;
		component->i++;
	}
	if (component->exit != 1 || component->player != 1
		|| component->collectible < 1)
		ft_print_error("Error\ninvalid components!");
}

void	ft_fload_fill(char **map, int i, int j)
{
	if (map[i][j] == EXIT)
		map[i][j] = WALL;
	if (map[i][j] == WALL || map[i][j] == CHECKED)
		return ;
	else
		map[i][j] = CHECKED;
	ft_fload_fill(map, i + 1, j);
	ft_fload_fill(map, i - 1, j);
	ft_fload_fill(map, i, j - 1);
	ft_fload_fill(map, i, j + 1);
}

void	check_comp(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != WALL && map[i][j] != CHECKED && map[i][j] != SPACE)
				ft_print_error("Error\nno acccess to every components of map!");
			j++;
		}
		j = 0;
		i++;
	}
}
