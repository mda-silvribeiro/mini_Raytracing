/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:05:20 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 13:05:09 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int	ft_close(t_data *data)
{
	ft_free_scene(data);
	exit(0);
}

void	ft_init_data(t_data *data)
{
	data->mlx.x_res = 0;
	data->mlx.y_res = 0;
	data->illum.ka = -1;
	data->camera = NULL;
	data->light = NULL;
	data->objects = NULL;
	data = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1 && ac < 4)
	{
		ft_bzero(&data, sizeof(t_data));
		ft_init_data(&data);
		ft_pars_scene(&data, av);
		if (ac == 2)
			ft_create_the_window(&data, av[1]);
		if (ac == 3 && (strncmp(av[2], "--save", 6) == 0
				|| strncmp(av[2], "-save", 5) == 0))
			ft_create_image(&data);
		else
			exit_error(&data, "the second arguments must be --save");
	}
	else
		exit_error(&data, "There's somthing wrong in arguments.");
	return (0);
}
