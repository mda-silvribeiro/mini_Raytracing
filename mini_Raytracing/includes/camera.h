/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:23:53 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:23:58 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt.h"

typedef struct s_camera
{
	t_vector			eye;
	t_vector			look_at;
	t_vector			v_up;
	double				fov;
	t_vector			w;
	t_vector			u;
	t_vector			v;
	t_vector			centre;
	t_vector			lower_left_corner;
	struct s_camera		*next;
	struct s_camera		*previous;
}				t_camera;

#endif
