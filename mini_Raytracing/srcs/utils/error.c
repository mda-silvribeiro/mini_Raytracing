/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:19:42 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 11:25:12 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_error(t_data *tmp, char *string)
{
	write(1, "ERROR\n", 6);
	write(1, string, ft_strlen(string));
	ft_free_scene(tmp);
	exit(1);
}

void	ft_checkColor(t_data *tmp, char **spt2)
{
	if (ft_argumentsCount(spt2) != 3)
		exit_error(tmp, "ERROR: RGB not defined");
	if (ft_strtod(spt2[0]) < 0 || ft_strtod(spt2[1]) < 0
		|| ft_strtod(spt2[2]) < 0 || ft_strtod(spt2[0]) > 255
		|| ft_strtod(spt2[1]) > 255 || ft_strtod(spt2[2]) > 255)
		exit_error(tmp, "ERROR: 0 to 255");
}

void	ft_checkVector(t_data *tmp, char **spt)
{
	if (ft_argumentsCount(spt) != 3)
		exit_error(tmp, "ERROR: Vector should be defined");
}

void	ft_checkVector2(t_data *tmp, char **spt)
{
	ft_checkVector(tmp, spt);
	if (ft_strtod(spt[0]) < -1 || ft_strtod(spt[1]) < -1
		|| ft_strtod(spt[2]) < -1 || ft_strtod(spt[0]) > 1
		|| ft_strtod(spt[1]) > 1 || ft_strtod(spt[2]) > 1)
		exit_error(tmp, "ERROR: You should use -1, 0 or 1.");
}

void	ft_checkScene(t_data *tmp)
{
	if (!tmp->mlx.x_res && !tmp->mlx.y_res)
		exit_error(tmp, "ERROR: Resolution should  be defined");
	if (tmp->illum.ka == -1)
		exit_error(tmp, "ERROR: Ambient Lighting not defined");
	if (tmp->camera == NULL)
		exit_error(tmp, "ERROR: unspecified camera");
}
