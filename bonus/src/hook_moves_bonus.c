/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:07:25 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/23 14:26:11 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_img_to_wind(t_data *data, mlx_image_t *image, int y, int x)
{
	int32_t	check;

	check = mlx_image_to_window(data->mlx, image, y, x);
	if (check < 0)
		ft_print_error("Error\nMlx Error!!");
}

void	ft_open_exit(t_data *data, char **str)
{
	(void)str;
	ft_printf("%d\n", data->moves++);
	ft_putendl_fd("you win 🥳🥳🥳", 0);
	ft_free_array(data->map);
	exit(0);
}

void	ft_moves(t_data *data, int new_x, int new_y)
{
	char	*str;

	if (data->map[new_x][new_y] == EXIT && !data->coll)
		ft_open_exit(data, &str);
	if (data->map[new_x][new_y] != WALL && data->map[new_x][new_y] != EXIT)
	{
		str = ft_itoa(data->moves);
		if (data->map[new_x][new_y] == COLLECTIBLE)
		{
			data->coll--;
			if (!data->coll)
				ft_img_to_wind(data, data->image6, data->e_y * 64, data->e_x
					* 64);
		}
		ft_img_to_wind(data, data->image1, new_y * 64, new_x * 64);
		ft_img_to_wind(data, data->image3, data->y * 64, data->x * 64);
		data->map[data->x][data->y] = '0';
		data->map[new_x][new_y] = 'P';
		ft_img_to_wind(data, data->image4, 0, 0);
		mlx_put_string(data->mlx, str, 24, 24);
		ft_free(&str);
		ft_printf("%d\n", data->moves++);
	}
}

void	ft_hook(mlx_key_data_t keydata, void *data_ptr)
{
	t_data	*data;

	data = data_ptr;
	data->coll = ft_collectibles(data->map);
	data->player_p = ft_position(data->map, PLAYER);
	data->exit_p = ft_position(data->map, EXIT);
	data->x = data->player_p[0];
	data->y = data->player_p[1];
	data->e_x = data->exit_p[0];
	data->e_y = data->exit_p[1];
	if (keydata.action && (keydata.key == MLX_KEY_RIGHT
			|| keydata.key == MLX_KEY_D))
		ft_moves(data, data->x, data->y + 1);
	else if (keydata.action && (keydata.key == MLX_KEY_LEFT
			|| keydata.key == MLX_KEY_A))
		ft_moves(data, data->x, data->y - 1);
	else if (keydata.action && (keydata.key == MLX_KEY_UP
			|| keydata.key == MLX_KEY_W))
		ft_moves(data, data->x - 1, data->y);
	else if (keydata.action && (keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_S))
		ft_moves(data, data->x + 1, data->y);
	else if (keydata.action && keydata.key == MLX_KEY_ESCAPE)
		exit(1);
	ft_free_tab(&(data->player_p), &(data->exit_p));
}
