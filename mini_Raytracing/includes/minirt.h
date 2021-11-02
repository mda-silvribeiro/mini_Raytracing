/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:25:30 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:47:12 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <math.h>
# include "minirt.h"
# include "vector.h"
# include "libft.h"
# include "camera.h"
# include "light.h"
# include "objects.h"
# include "utils.h"
# include "parsing.h"
# include "get_next_line.h"
# include "scene.h"
# include "intersection.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>

# define SP 100
# define PL 101
# define SQ 102
# define TR 103
# define CY 104
# define ESC 53
# define NEXT_CAM 45
# define PREV_CAM 35

void		ft_checkRotation(t_data *data, t_camera *cam, char **s_line);
void		ft_checkObjs(t_data *data, t_objects *obj, char **s_line);
void		ft_checkTransLight(t_data *tmp, t_light *light, char **string);
t_vector	ft_rotation(t_vector rot, t_vector normal);
t_vector	ft_trans(t_vector position, t_vector trans);

#endif
