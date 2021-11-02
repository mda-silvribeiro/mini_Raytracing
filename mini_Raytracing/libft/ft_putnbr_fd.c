/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:54:56 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 08:33:59 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		write(fd, "-", 1);
		number = (unsigned int)(n * -1);
	}
	else
		number = (unsigned int)n;
	if (number > 9)
		ft_putnbr_fd(number / 10, fd);
	write(fd, &"0123456789"[number % 10], 1);
}
