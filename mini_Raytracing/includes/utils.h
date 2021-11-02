/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:48:02 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:48:04 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_file_header
{
	char	file_type[2];
	int		file_size;
	int		reversed;
	int		offset_bits;
}				t_file_header;

typedef struct s_infos_header
{
	int			header_size;
	int			img_width;
	int			img_height;
	short int	planes;
	short int	bits_per_pixel;
	int			compression;
	int			image_size;
	int			x_pixel_per_meter;
	int			y_pixel_per_meter;
	int			colors;
	int			important_colors;
}				t_infos_header;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	x_res;
	double	y_res;
	double	viewport_height;
	double	viewport_width;
}				t_mlx;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dest;
}				t_ray;

typedef struct s_hit_rec
{
	double		t;
	double		t_closest;
	double		m;
	t_vector	hit_point;
	t_vector	normal;
	t_vector	light_ray;
	t_vector	view;
}				t_hit_rec;

typedef struct s_objects
{
	t_sphere			sphere;
	t_plane				plane;
	t_triangle			triangle;
	t_square			square;
	t_cylinder			cylinder;
	int					obj_type;
	struct s_objects	*next;
}				t_objects;

typedef struct s_data
{
	t_objects	*objects;
	t_camera	*camera;
	t_ray		ray;
	t_light		*light;
	t_illum		illum;
	t_hit_rec	rec;
	t_mlx		mlx;
	t_img		img;
	t_vector	rotation;
	t_vector	translation;
	int			color[3];
	double		shadow;
}				t_data;

void	ft_create_the_window(t_data *data, char *name_program);
void	ft_create_image_bmp(t_data *data);
void	ft_create_image(t_data *data);
int		set_key(int button, t_data *data);
int		ft_close(t_data *data);
int		main(int ac, char **av);

#endif
