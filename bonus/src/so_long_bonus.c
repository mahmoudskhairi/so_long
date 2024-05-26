/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:13:59 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/26 06:31:25 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_texture_to_image(t_data *data)
{
	data->image1 = mlx_texture_to_image(data->mlx, data->texture1);
	if (!data->image1)
		ft_print_error("Error\ntexture to images!!");
	data->image2 = mlx_texture_to_image(data->mlx, data->texture2);
	if (!data->image2)
		ft_print_error("Error\ntexture to images!!");
	data->image3 = mlx_texture_to_image(data->mlx, data->texture3);
	if (!data->image3)
		ft_print_error("Error\ntexture to images!!");
	data->image4 = mlx_texture_to_image(data->mlx, data->texture4);
	if (!data->image4)
		ft_print_error("Error\ntexture to images!!");
	data->image5 = mlx_texture_to_image(data->mlx, data->texture5);
	if (!data->image5)
		ft_print_error("Error\ntexture to images!!");
	data->image6 = mlx_texture_to_image(data->mlx, data->texture6);
	if (!data->image6)
		ft_print_error("Error\ntexture to images!!");
}

void	ft_init_data(t_data *data)
{
	data->texture1 = mlx_load_png("Images/player2.png");
	if (!data->texture1)
		ft_print_error("Error\nload png!!");
	data->texture2 = mlx_load_png("Images/exit_after.png");
	if (!data->texture2)
		ft_print_error("Error\nload png..!!");
	data->texture3 = mlx_load_png("Images/space.png");
	if (!data->texture3)
		ft_print_error("Error\nload png!!");
	data->texture4 = mlx_load_png("Images/wall.png");
	if (!data->texture4)
		ft_print_error("Error\nload png!!");
	data->texture5 = mlx_load_png("Images/collectible.png");
	if (!data->texture5)
		ft_print_error("Error\nload png!!");
	data->texture6 = mlx_load_png("Images/exit!.png");
	if (!data->texture6)
		ft_print_error("Error\nload png!!");
	ft_texture_to_image(data);
	ft_delete_texture(data);
}

void	ft_set_images(void *mlx, t_data *data, int i, int j)
{
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == PLAYER &&
				mlx_image_to_window(mlx, data->image1, data->x, data->y) < 0)
				ft_print_error("Error\nImage To Window!!");
			else if (data->map[i][j] == EXIT && mlx_image_to_window(mlx,
						data->image2, data->x, data->y) < 0)
				ft_print_error("Error\nImage To Window!!");
			else if (data->map[i][j] == SPACE && mlx_image_to_window(mlx,
						data->image3, data->x, data->y) < 0)
				ft_print_error("Error\nImage To Window!!");
			else if (data->map[i][j] == WALL && mlx_image_to_window(mlx,
						data->image4, data->x, data->y) < 0)
				ft_print_error("Error\nImage To Window!!");
			else if (data->map[i][j] == COLLECTIBLE && mlx_image_to_window(mlx,
						data->image5, data->x, data->y) < 0)
				ft_print_error("Error\nImage To Window!!");
			data->x = data->x + 64;
		}
		data->x = 0;
		data->y = data->y + 64;
	}
}

void	ft_graphic(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	data->x = 0;
	data->y = 0;
	data->moves = 1;
	data->mlx = mlx_init(ft_strlen(data->map[0]) * 64, ft_lineslen(data->map)
			* 64, "-", 1);
	if (!data->mlx)
		ft_print_error("Error\nMlx Error!");
	ft_init_data(data);
	ft_set_images(data->mlx, data, i, j);
	mlx_key_hook(data->mlx, &ft_hook, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->image1);
	mlx_delete_image(data->mlx, data->image2);
	mlx_delete_image(data->mlx, data->image3);
	mlx_delete_image(data->mlx, data->image4);
	mlx_delete_image(data->mlx, data->image5);
	mlx_delete_image(data->mlx, data->image6);
	mlx_terminate(data->mlx);
}

int	main(int ac, char *av[])
{
	t_data	data;
	int		fd;

	data.map = NULL;
	data.mapcpy = NULL;
	if (ac == 2)
	{
		if (ft_check_filename(av[1]))
			ft_print_error("Error\n:(.ber!)");
		fd = open(av[1], O_RDONLY, 0777);
		if (fd == -1)
			ft_print_error("Error\ninvalid path of map!");
		ft_read_file(fd, &(data));
		ft_check_maps(data.mapcpy);
	}
	else
		ft_print_error("Error\ninvalid number of arguments!");
	if (ft_strlen(data.map[0]) > 40 || ft_lineslen(data.map) > 21)
		ft_print_error("Error\nbig map!");
	ft_graphic(&data);
	ft_free_array(data.map);
}
