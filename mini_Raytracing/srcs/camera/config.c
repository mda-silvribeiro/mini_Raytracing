/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:31:34 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:31:36 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_configLight(t_light **alst, t_light *new)
{
	if (!*alst)
	{
		*alst = new;
	}
	else if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_configObjects(t_objects **alst, t_objects *new)
{
	if (!*alst)
	{
		*alst = new;
	}
	else if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

static t_camera	*ft_lstlast_camera(t_camera *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		return (lst);
	}
	return (NULL);
}

void	ft_configCams(t_camera **alst, t_camera *new)
{
	t_camera	*temp;

	if (*alst)
	{
		temp = ft_lstlast_camera(*alst);
		temp->next = new;
		new->next = NULL;
		new->previous = temp;
	}
	else
		*alst = new;
}
