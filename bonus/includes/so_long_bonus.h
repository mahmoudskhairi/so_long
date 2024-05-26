/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:20:12 by mskhairi          #+#    #+#             */
/*   Updated: 2024/05/26 06:35:30 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../../MLX42/include/MLX42/MLX42.h"
# include "../../ft_printf/ft_printf.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"

# define PLAYER 80
# define EXIT 69
# define COLLECTIBLE 67
# define WALL 49
# define SPACE 48
# define CHECKED 45

typedef struct data
{
	char			**map;
	char			**mapcpy;
	int				*player_p;
	int				*exit_p;
	void			*mlx;
	int				x;
	int				y;
	int				e_x;
	int				e_y;
	int				moves;
	int				coll;
	mlx_texture_t	*texture1;
	mlx_texture_t	*texture2;
	mlx_texture_t	*texture3;
	mlx_texture_t	*texture4;
	mlx_texture_t	*texture5;
	mlx_texture_t	*texture6;
	mlx_texture_t	*texture7;
	mlx_image_t		*image1;
	mlx_image_t		*image2;
	mlx_image_t		*image3;
	mlx_image_t		*image4;
	mlx_image_t		*image5;
	mlx_image_t		*image6;
	mlx_image_t		*image7;
}					t_data;

typedef struct component
{
	int				collectible;
	int				exit;
	int				player;
	int				i;
	int				j;
}					t_component;

int					ft_lineslen(char **map);
void				ft_read_file(int fd, t_data *data);
int					ft_check_filename(char *str);
void				ft_check_maps(char **map);
void				ft_fload_fill(char **map, int i, int j);
void				check_comp(char **map);
void				ft_init_comp(t_component *component);
void				ft_check_components(char **map, t_component *component);
int					*ft_position(char **map, char c);
void				ft_hook(mlx_key_data_t keydata, void *data_ptr);
int					ft_collectibles(char **map);
void				ft_delete_texture(t_data *data);
void				ft_print_mlx_error(t_data *data, char *str);
void				check_leaks(void);
#endif