/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 07:59:00 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/26 06:32:21 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_lineslen(char **map)
{
	int	lines;
	int	i;

	i = 0;
	lines = 0;
	while (map[i++])
		lines++;
	return (lines);
}

void	ft_read_file(int fd, t_data *data)
{
	char	*str;
	char	*tmp1;
	char	*tmp2;

	data->map = NULL;
	str = ft_strdup("");
	tmp1 = get_next_line(fd);
	if (!tmp1 || tmp1[0] == '\n')
		ft_print_error("Error\nempty map!");
	while (tmp1)
	{
		tmp2 = tmp1;
		if (tmp1[0] == '\n')
			ft_print_error("Error\nempty line!");
		str = ft_strjoin(str, tmp1);
		ft_free(&tmp1);
		tmp1 = get_next_line(fd);
	}
	data->map = ft_split(str, '\n');
	data->mapcpy = ft_split(str, '\n');
	ft_free(&str);
}

int	ft_check_filename(char *str)
{
	int	i;
	int	search_d;

	search_d = ft_strlen(str) - 4;
	i = ft_strcmp((str + search_d), ".ber");
	return (i);
}

void	ft_delete_texture(t_data *data)
{
	mlx_delete_texture(data->texture1);
	mlx_delete_texture(data->texture2);
	mlx_delete_texture(data->texture3);
	mlx_delete_texture(data->texture4);
	mlx_delete_texture(data->texture5);
	mlx_delete_texture(data->texture6);
}
