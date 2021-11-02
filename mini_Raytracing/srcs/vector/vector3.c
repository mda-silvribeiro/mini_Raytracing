/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:00:08 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 13:00:59 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	ft_trans(t_vector position, t_vector trans)
{
	return (new_vec(position.x + trans.x, position.y + trans.y,
			position.z + trans.z));
}

void	ft_checkTransLight(t_data *tmp, t_light *light, char **string)
{
	char	**args;

	if (ft_argumentsCount(string) == 5)
	{
		args = ft_split(string[4], ',');
		ft_checkVector(tmp, args);
		tmp->translation = parser_vector(args);
		light->position = ft_trans(light->position,
				tmp->translation);
	}
}
