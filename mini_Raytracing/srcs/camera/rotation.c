/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:29:41 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:30:54 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	r_x(t_vector normal, double tetha)
{
	t_vector	tmp;

	tetha = tetha * (M_PI / 180);
	tmp.x = normal.x;
	tmp.y = normal.y * cos(tetha) - normal.z * sin(tetha);
	tmp.z = normal.y * sin(tetha) + normal.z * cos(tetha);
	return (tmp);
}

t_vector	r_y(t_vector normal, double tetha)
{
	t_vector	tmp;

	tetha = tetha * (M_PI / 180);
	tmp.x = normal.x * cos(tetha) + normal.z * sin(tetha);
	tmp.y = normal.y;
	tmp.z = normal.z * cos(tetha) - normal.x * sin(tetha);
	return (tmp);
}

t_vector	r_z(t_vector normal, double tetha)
{
	t_vector	tmp;

	tetha = tetha * (M_PI / 180);
	tmp.x = normal.x * cos(tetha) - (normal.y * sin(tetha));
	tmp.y = normal.x * sin(tetha) + normal.y * cos(tetha);
	tmp.z = normal.z;
	return (tmp);
}

t_vector	ft_rotation(t_vector rot, t_vector normal)
{
	t_vector	vec;

	vec.x = normal.x;
	vec.y = normal.y;
	vec.z = normal.z;
	vec = r_x(vec, rot.x);
	vec = r_y(vec, rot.y);
	vec = r_z(vec, rot.z);
	vec = ft_normalize(vec);
	return (vec);
}

void	ft_checkRotation(t_data *data, t_camera *cam, char **s_line)
{
	char	**s_arg;

	if (ft_argumentsCount(s_line) > 4)
	{
		if (s_line[4])
		{
			s_arg = ft_split(s_line[4], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please Check the rotation in camera.");
			data->rotation = parser_vector(s_arg);
			cam->look_at = ft_rotation(data->rotation, cam->look_at);
		}
		if (s_line[5])
		{
			s_arg = ft_split(s_line[5], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please Check the translation in camera.");
			data->translation = parser_vector(s_arg);
			cam->eye = ft_trans(cam->eye, data->translation);
		}
	}
}
