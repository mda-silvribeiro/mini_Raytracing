/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:36:10 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 11:02:33 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser_ambiant_light(t_data *data, char *line)
{
	char	**sl;
	char	**split_arg;

	if (data->illum.amb_col.r != 0 || data->illum.amb_col.g != 0
		|| data->illum.amb_col.b != 0 || data->illum.ka != -1)
		exit_error(data, "The ambiant lighting use once in scene.");
	sl = ft_split(line, ' ');
	if (ft_argumentsCount(sl) != 3)
		exit_error(data, "The ambiant lighting have a color and ratio.");
	if (ft_strchr(sl[1], ','))
		exit_error(data, "Check the ambient ratio.");
	if (ft_strtod(sl[1]) < 0 || ft_strtod(sl[1]) > 1
		|| ft_strchr(sl[1], ','))
		exit_error(data, "Check the ambient ratio.");
	data->illum.ka = ft_strtod(sl[1]);
	split_arg = ft_split(sl[2], ',');
	ft_checkColor(data, split_arg);
	data->illum.amb_col = parser_color(split_arg);
	ft_free_split(split_arg);
	ft_free_split(sl);
}

void	parser_light(t_data *data, char *line)
{
	t_light	*light;
	char	**sl;
	char	**split_arg;

	light = malloc(sizeof(t_light));
	if (!light)
		exit_error(data, "Allocation error.");
	sl = ft_split(line, ' ');
	if (ft_argumentsCount(sl) < 4 || ft_argumentsCount(sl) > 5)
		exit_error(data, "Check the light scene.");
	if (ft_strtod(sl[2]) < 0 || ft_strtod(sl[2]) > 1 || ft_strchr(sl[2], ','))
		exit_error(data, "check the brightnes ratio at light.");
	light->kd = ft_strtod(sl[2]);
	split_arg = ft_split(sl[1], ',');
	ft_checkVector(data, split_arg);
	light->position = parser_vector(split_arg);
	split_arg = ft_split(sl[3], ',');
	ft_checkColor(data, split_arg);
	light->intensity = parser_color(split_arg);
	ft_free_split(split_arg);
	ft_checkTransLight(data, light, sl);
	ft_free_split(sl);
	light->next = NULL;
	ft_configLight(&data->light, light);
}

void	parser_camera(t_data *data, char *line)
{
	t_camera	*camera;
	char		**sl;
	char		**split_arg;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		exit_error(data, "Allocation error.");
	sl = ft_split(line, ' ');
	if (ft_argumentsCount(sl) < 4 || ft_argumentsCount(sl) > 6)
		exit_error(data, "Please! Check the camera in the scene.");
	split_arg = ft_split(sl[1], ',');
	ft_checkVector(data, split_arg);
	camera->eye = parser_vector(split_arg);
	split_arg = ft_split(sl[2], ',');
	ft_checkVector2(data, split_arg);
	camera->look_at = parser_vector(split_arg);
	ft_free_split(split_arg);
	if (ft_strtod(sl[3]) < 0 || ft_strtod(sl[3]) > 180 || ft_strchr(sl[3], ','))
		exit_error(data, "Please! Check the field of view in camera.");
	camera->fov = ft_strtod(sl[3]);
	ft_checkRotation(data, camera, sl);
	camera->next = NULL;
	camera->previous = NULL;
	ft_free_split(sl);
	ft_configCams(&data->camera, camera);
}
