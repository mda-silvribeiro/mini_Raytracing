/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:47:22 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:47:24 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

t_color		ambient_light(t_data *data);
t_color		deffuse_light(t_data *data, t_light *light);
t_color		specular_light(t_data *data, t_light *light, double shine_factor);
t_color		color_final_pixel(t_data *data, t_objects *obj, t_color deff_col,
				t_color spec_col);
t_color		get_deffuse_at_point(t_data *data, t_light *tmp_light,
				t_color deff0);
t_color		get_spec_at_point(t_data *data, t_light *tmp_light, t_objects *obj,
				t_color spec0);
void		ft_rayTracing(t_data *data, t_camera *camera);
t_color		scene_trace(t_data *data);
void		ft_camWport(t_data *data, t_camera *camera);
t_ray		ft_configRayT(t_data *data, t_camera *camera, int i, int j);
void		wich_camera(int button, t_data *data);

#endif
