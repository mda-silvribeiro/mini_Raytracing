/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:04:39 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:08:23 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_calcul_vec(t_camera *cam)
{
	cam->w = cam->look_at;
	cam->w = ft_multScal(-1, cam->look_at);
	cam->w = ft_normalize(cam->w);
	cam->u = ft_cross(&cam->v_up, &cam->w);
	cam->u = ft_normalize(cam->u);
	cam->v = ft_cross(&cam->w, &cam->u);
}

void	ft_camWport(t_data *data, t_camera *cam)
{
	double		aspect_ratio;
	double		tetha;
	t_vector	tmp;

	cam->v_up = new_vec(0, 1, 0);
	if ((cam->look_at.y > 0 || cam->look_at.y < 0)
		&& (cam->look_at.x == 0 && cam->look_at.z == 0))
		cam->v_up = new_vec(0, 0, -1);
	tetha = cam->fov * M_PI / 180;
	aspect_ratio = data->mlx.x_res / data->mlx.y_res;
	data->mlx.viewport_height = 2.0 * tan(-tetha / 2);
	data->mlx.viewport_width = aspect_ratio * data->mlx.viewport_height;
	ft_calcul_vec(cam);
	data->ray.origin = cam->eye;
	cam->centre = ft_subtraction(&cam->eye, &cam->w);
	tmp = ft_multScal(data->mlx.viewport_width / 2, cam->u);
	cam->lower_left_corner = ft_subtraction(&cam->centre, &tmp);
	tmp = ft_multScal(data->mlx.viewport_height / 2.0, cam->v);
	cam->lower_left_corner = ft_subtraction(&cam->lower_left_corner, &tmp);
}

t_ray	ft_configRayT(t_data *data, t_camera *cam, int i, int j)
{
	t_vector	pixel_pos;
	t_vector	tmp;

	tmp = ft_multScal((i + 0.5) * data->mlx.viewport_width
			/ data->mlx.x_res, cam->u);
	pixel_pos = ft_add(&cam->lower_left_corner, &tmp);
	tmp = ft_multScal((j + 0.5) * data->mlx.viewport_height
			/ data->mlx.y_res, cam->v);
	pixel_pos = ft_add(&pixel_pos, &tmp);
	data->ray.dest = ft_subtraction(&pixel_pos, &data->ray.origin);
	data->ray.dest = ft_normalize(data->ray.dest);
	return (data->ray);
}
