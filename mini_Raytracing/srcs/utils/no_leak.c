/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leak.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:36:16 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 11:37:27 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_free_cameras(t_camera *camera)
{
	t_camera	*cam_to_free;

	cam_to_free = NULL;
	while (camera != NULL)
	{
		cam_to_free = camera;
		camera = camera->next;
		free(cam_to_free);
		cam_to_free = NULL;
	}
}

void	ft_free_lights(t_light *light)
{
	t_light	*light_to_free;

	light_to_free = NULL;
	while (light != NULL)
	{
		light_to_free = light;
		light = light->next;
		free(light_to_free);
		light_to_free = NULL;
	}
}

void	ft_free_objects(t_objects *objects)
{
	t_objects	*obj_to_free;

	obj_to_free = NULL;
	while (objects != NULL)
	{
		obj_to_free = objects;
		objects = objects->next;
		free(obj_to_free);
		obj_to_free = NULL;
	}
}

void	ft_free_scene(t_data *data)
{
	if (data != NULL)
	{
		if (data->camera != NULL)
			ft_free_cameras(data->camera);
		if (data->light != NULL)
			ft_free_lights(data->light);
		if (data->objects != NULL)
			ft_free_objects(data->objects);
	}
}
